#!/bin/bash

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
echo " Force building bin/print_canonical"
make bin/print_canonical bin/eval_expr -B
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
fi


for DRIVER in test_deliverable/test_cases/*_driver.c ; do
	NAME=$(basename $DRIVER _driver.c)
	TESTCODE=test_deliverable/test_cases/$NAME.c


#need to edit for these functionalities


echo "========================================="
echo "Checking that good expressions are parsed"

PASSED=0
CHECKED=0

if [[ -f test/valid_expressions.got.txt ]]; then
    rm test/valid_expressions.got.txt
fi
while IFS=, read -r INPUT_LINE REF_LINE BINDINGS REF_VALUE; do
    echo "==========================="
    echo ""
    echo "Input : ${INPUT_LINE}"
    GOT_LINE=$( echo -n "${INPUT_LINE}" | bin/print_canonical )
    echo "Output : ${GOT_LINE}"
    if [[ "${GOT_LINE}" != "${REF_LINE}" ]]; then
        echo ""
        echo "ERROR"
    else
        PASSED=$(( ${PASSED}+1 ));
    fi
    CHECKED=$(( ${CHECKED}+1 ));

    echo ""
    echo "Evaluating with : $BINDINGS"
    GOT_VALUE=$( echo -n "${INPUT_LINE}" | bin/eval_expr ${BINDINGS} )
    echo "Value : ${GOT_VALUE}"
    if [[ "${GOT_VALUE}" != "${REF_VALUE}" ]]; then
        echo ""
        echo "ERROR"        
    else
        PASSED=$(( ${PASSED}+1 ));
    fi
    CHECKED=$(( ${CHECKED}+1 ));
    
    echo "${INPUT_LINE},${GOT_LINE},${BINDINGS},${GOT_VALUE}" >> test/valid_expressions.got.txt

done < <( cat test/valid_expressions.input.txt | ${DOS2UNIX})

echo ""
echo "============================================"
echo "Checking that bad expressions are not parsed"
echo ""

while IFS=, read -r INPUT_LINE; do
    # Strip carriage return if necessary (replace dos2unix)
    INPUT_LINE=$(echo ${INPUT_LINE})
    echo "==========================="
    echo ""
    echo "Input : ${INPUT_LINE}"
    GOT_LINE=$( echo -n "${INPUT_LINE}" | bin/print_canonical )
    CODE=$?;
    echo "Output : ${GOT_LINE}"
    if [[ ${CODE} -eq "0" ]]; then
        echo ""
        echo "ERROR"
        PASSED=$(( ${PASSED}-1 ));        
    fi
done < <( cat test/invalid_expressions.input.txt | ${DOS2UNIX} )


echo "########################################"
echo "Passed ${PASSED} out of ${CHECKED} checks".
echo ""

RELEASE=$(lsb_release -d)
if [[ $? -ne 0 ]]; then
    echo ""
    echo "Warning: This appears not to be a Linux environment"
    echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
else
    grep -q "Ubuntu 16.04" <(echo $RELEASE)
    FOUND=$?

    if [[ $FOUND -ne 0 ]]; then
        echo ""
        echo "Warning: This appears not to be the target environment"
        echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
    fi
fi

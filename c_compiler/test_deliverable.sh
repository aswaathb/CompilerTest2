#!/bin/bash

echo "========================================"
echo "Cleaning the temporaries and outputs"
make clean

mkdir -p working

COMPILER=bin/c_compiler
FAILED=0
CHECKED=0

for DRIVER in test_deliverable/test_cases/*_driver.c ; do
	NAME=$(basename $DRIVER _driver.c)
	TESTCODE=test_deliverable/test_cases/$NAME.c

	# Compile driver with normal GCC
	mips-linux-gnu-gcc -c $DRIVER -o working/${NAME}_driver.o 2> working/${NAME}_driver.compile.stderr
	if [[ $? -ne 0 ]]; then
		echo "Test case: ${NAME}. ERROR : Couldn't compile driver program using GCC."
		continue
	fi

	# Compile test function with compiler to assembly
	cat $TESTCODE | $COMPILER > working/$NAME.s  2> working/${NAME}.compile.stderr
	if [[ $? -ne 0 ]]; then
		echo "Test case: ${NAME}. ERROR : Compiler returned error message."
		continue
	fi

	# Link driver object and assembly into executable
	mips-linux-gnu-gcc -static working/${NAME}.s working/${NAME}_driver.o -o working/${NAME}.elf 2> working/${NAME}.link.stderr
	if [[ $? -ne 0 ]]; then
		echo "Test case: ${NAME}. ERROR : Linker returned error message."
	continue
	fi

	# Run the actual executable
	qemu-mips working/${NAME}.elf
	RESULT=$?
	echo "${NAME}"
	if [[ $result -ne 0 ]]; then
		echo "Test case: ${NAME}. ERROR : Testcase returned ${RESULT}, but expected 0."
		FAILED=$(( ${FAILED}+1 ));
	fi
	echo "passed"
	CHECKED=$(( ${CHECKED}+1 ));

done

echo "########################################"
echo "FAILED ${FAILED} out of ${CHECKED} checks".

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

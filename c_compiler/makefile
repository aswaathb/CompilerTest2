CXXFLAGS += -std=c++11 -W -Wall -g
# Set constant directorys
LSDIR=src	###################
PSDIR=src	####################
CSDIR=src   ###################

INC=-Iinclude
# Preprocessor flags, MMD creates dependency files
CPPFLAGS += -MMD $(INC)

FLX = $(LSDIR)/lexer.yy.cpp
BIS = $(PSDIR)/parser.tab.c

###
### BUILD RULES FOR LEXER
###
# List of source files for lexer
#LSRCS= $(LSDIR)/lexer_main.cpp $(FLX)   ########################
bin/lexer.yy.cpp : src/lexer.flex				###############
		flex -o bin/lexer.yy.cpp  src/lexer.flex   #######################

bin/lexer: src/parser.tab.hpp $(LSRCS:%.cpp=%.o) 
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/lexer -o  bin/lexer.yy.cpp ###################

src/parser.tab.hpp: src/parser.y
	bison -d -o src/parser.tab.cpp $^

# Need to generate lexer.yy.cpp from .flex first
%/lexer.yy.cpp: %/lexer.flex src/parser.tab.hpp
	flex -o $@ $^ 

# Need to build lexer.yy.o next
%/lexer.yy.o: lexer.yy.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

-include $(_LSRCS:%.cpp=%.d)

###
### BUILD RULES FOR PARSER
###
# Source files
#PSRCS=$(PSDIR)/parser_main.cpp	########################
#-include $(PSRCS:%.cpp=%.d)	#######################
PSRCS += $(FLX) $(BIS)
PSRCS += $(wildcard include/ast/*.cpp) ############

bin/parser: src/parser.tab.hpp $(PSRCS:%.cpp=%.o) 
	mkdir -p bin
	g++ $(CPPFLAGS) $(CXXFLAGS) -o $@ $(PSRCS:%.cpp=%.o)

%/parser.tab.cpp: src/parser.tab.hpp

# Need to generate lexer.yy.cpp from .flex first
%/lexer.yy.cpp: %/lexer.flex src/parser.tab.hpp
	flex -o $@ $^ 

###
### BUILD RULES FOR COMPILER
###
# Source files
#CSRCS=$(CSDIR)/compiler_main.cpp ############################
#-include $(CSRCS:%.cpp=%.d)		######################
CSRCS += $(FLX) $(BIS)
CSRCS += $(wildcard include/ast/*.cpp) #############

bin/compiler : src/parser.tab.hpp $(CSRCS:%.cpp=%.o)
	mkdir -p bin
	g++ $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

all : bin/lexer bin/parser bin/compiler

clean:
	rm -f bin/*


	rm -f src/*.o
	rm -f src/*.d
	rm -f src/*.tab.*
	rm -f src/*.yy.*
	rm -f src/ast/*.o
	rm -f src/ast/*.d
	rm -f test/compiler/out/*
	rm -f test/compiler/ref/*

.PHONY: clean

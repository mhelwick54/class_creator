TARGET=create
CFLAGS= -std=c++17 -Wall
OPT_LVL=
LDFLAGS=-I$(IDIR)

IDIR=./include
SDIR=./src
ODIR=./bin

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	ifeq ($(shell which gcc-8), /usr/local/bin/gcc-8)
		CC=gcc-8#MacOS GNU gcc, not clang
		CXX=g++-8
	else
		CC=clang
		CXX=clang
	endif
else
	CC=gcc#GNU gcc
	CXX=gcc
endif

_DEPS=main.h error.h class_structure.h string_funcs.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC=main.cpp error.cpp class_structure.cpp string_funcs.cpp
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ=main.o error.o class_structure.o string_funcs.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(ODIR)/$(TARGET)
	@printf "%b" "Compilation successful\n"

$(ODIR)/$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) $(OPT_LVL) $(LDFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) $(CFLAGS) $(OPT_LVL) -MMD -c $< -o $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*

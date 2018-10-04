# The compiler to use
CC=$(CCPREFIX)g++

# Compiler flags
CFLAGS=-Wall -std=c++11
    # -Wall: This enables all the warnings about constructions that some users consider questionable,
		#			and that are easy to avoid (or modify to prevent the warning), even in conjunction with macros.

# LDFLAGS=

# Libraries
LIBS=-li2cendpoint

# Sources and executables
SRCDIR=.
BUILDDIR=../bin/examples

SOURCE_FILES := $(shell find $(SRCDIR) -name '*.cpp')
EXECUTABLES := $(patsubst %.cpp,%,$(shell find $(SRCDIR) -name '*.cpp'))

all: makebuildir $(EXECUTABLES)

% : %.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $(BUILDDIR)/$@ $(LIBS)

clean :
	rm -rf $(BUILDDIR)

makebuildir:
	mkdir -p $(BUILDDIR)
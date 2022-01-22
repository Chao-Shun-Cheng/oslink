CC = arm-linux-gnueabihf-g++
CFLAGS = -std=c++1z  -march=armv7-a -mfloat-abi=hard -mfpu=vfpv3-d16 -mthumb
#-Wall -Wextra
LIB_PATH := $(realpath lib)
LDFLAGS = -g -L$(LIB_PATH) 
LIB_FILES := $(wildcard $(LIB_PATH)/*.so)

LIBS = -ldsrc_v2xcast -pthread -lrt -lm -lzmq
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
EXEC_DIR  := $(BUILD)/exec
TARGET = oslink

INCLUDE  := -g -I$(realpath include/)
INC_PATH := include
INCLUDE_FILE := $(wildcard $(INCLUDE_DIR)/*.h)

linker_opt = -Wl,-rpath,'$$ORIGIN/../../lib'

SRCDIR = src
SRC      := $(wildcard $(SRCDIR)/*.cc)         
OBJECTS  := $(SRC:%.cc=$(OBJ_DIR)/%.o)

all: build $(EXEC_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

#$ORIGIN represents the directory in which an object originated.
$(EXEC_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(EXEC_DIR)/$(TARGET) $^ $(LDFLAGS) $(LIBS) $(linker_opt)

.PHONY:clean format build
build:
	@mkdir -p $(EXEC_DIR)
	@mkdir -p $(OBJ_DIR)
format:
	clang-format \
	-style=\
	"{BasedOnStyle: Google,BreakBeforeBraces: Stroustrup, IndentWidth: 4, IndentCaseLabels: false, TabWidth: 4, UseTab: ForIndentation, ColumnLimit: 0}"\
	 -i $(SRC) $(wildcard $(INC_PATH)/*.cc) $(wildcard $(INC_PATH)/*.h) 
clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(EXEC_DIR)/* 
	-@rm -rvf build

CC=gcc

SourceDir=./src/
ObjDir=./bin/
BuildDir=./build/
INCS=-I./inlcudes

SRCS=$(wildcard $(SourceDir)/*.c)



Obj=$(subst $(SourceDir)/%.c, $(ObjDir)/%.o , $(SRCS))

program=calculator.elf

all:$(BuildDir)/$(program)




$(ObjDir)/%.o: $(SourceDir)/%.c | $(BuildDir)
	$(CC) $(INCS) -c $< -o $@
	

$(BuildDir)/$(program): $(Obj) | $(BuildDir)
	$(CC) $(INCS) $^ -o $( BuildDir) $@
	
.PHONY: clean
clean:
	-rf $(BuildDir) $(ObjDir)




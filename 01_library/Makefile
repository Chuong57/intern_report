
CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc

OBJ_DIR := $(CUR_DIR)/obj
OBJ_SHARED := $(OBJ_DIR)/shared
OBJ_STATIC := $(OBJ_DIR)/static

SRC_DIR := $(CUR_DIR)/src

LIB_DIR := $(CUR_DIR)/lib
LIB_SHARED := $(LIB_DIR)/shared
LIB_STATIC := $(LIB_DIR)/static

object_shared:
	gcc -c -fPIC $(CUR_DIR)/main.c -o $(OBJ_SHARED)/main.o -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/math.c -o $(OBJ_SHARED)/math.o -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/version.c -o $(OBJ_SHARED)/version.o -I $(INC_DIR)

object_static:
	gcc -c $(CUR_DIR)/main.c -o $(OBJ_STATIC)/main.o -I $(INC_DIR)
	gcc -c $(SRC_DIR)/math.c -o $(OBJ_STATIC)/math.o -I $(INC_DIR)
	gcc -c $(SRC_DIR)/version.c -o $(OBJ_STATIC)/version.o -I $(INC_DIR)

create_shared:
	gcc -shared $(OBJ_SHARED)/math.o $(OBJ_SHARED)/version.o -o $(LIB_SHARED)/libshared.so

create_static:
	ar rcs $(LIB_STATIC)/libstatic.a $(OBJ_STATIC)/math.o $(OBJ_STATIC)/version.o

linking:
	gcc $(OBJ_SHARED)/main.o -L $(LIB_SHARED) -l shared -o $(BIN_DIR)/use_shared
	gcc $(OBJ_STATIC)/main.o -L $(LIB_STATIC) -l static -o $(BIN_DIR)/use_static

install:
	cp $(LIB_SHARED)/libshared.so /usr/lib/

all:  object_shared object_static create_shared create_static linking install

clean:
	rm -rf $(OBJ_SHARED)/*.o
	rm -rf $(OBJ_STATIC)/*.o
	rm -rf $(LIB_STATIC)/* $(LIB_SHARED)/*
	rm -rf $(BIN_DIR)/*
	rm -rf /usr/lib/libshared.so
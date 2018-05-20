ALL: atom

SRC_DIR := src/core
OBJ_DIR := obj
LIB_DIR := lib

atom: $(OBJ_DIR)/atom.o
	g++ -shared -o $(LIB_DIR)/atom.dll $(OBJ_DIR)/atom.o -DATOM_STATIC -DWindows -D_WIN32 -lglut32 -lopengl32 -lglu32 -static-libgcc -static-libstdc++

$(OBJ_DIR)/atom.o: $(SRC_DIR)/atom.cpp $(SRC_DIR)/atom.h
	g++ -c $(SRC_DIR)/atom.cpp -o $(OBJ_DIR)/atom.o

clean:
	rm obj *.o *~ 
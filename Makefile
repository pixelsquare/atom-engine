ALL: atom

# CXX = g++
CXXFLAGS = -shared -g -Wall -Wfatal-errors -DATOM_STATIC -lglut32 -lopengl32 -lglu32 -static-libgcc -std=c++14 -static-libstdc++

SRC_DIR := src/core
OBJ_DIR := obj
LIB_DIR := lib

atom: $(OBJ_DIR)/atom.o
	$(CXX) $(CXXFLAGS) -o $(LIB_DIR)/atom.dll $(OBJ_DIR)/atom.o 

$(OBJ_DIR)/atom.o: $(SRC_DIR)/atom.cpp $(SRC_DIR)/atom.h
	$(CXX) -c $(SRC_DIR)/atom.cpp -o $(OBJ_DIR)/atom.o

clean:
	rm obj *.o *~ 
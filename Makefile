ALL: atom

# CXX = g++
CXXFLAGS = -shared -g -Wall -Wfatal-errors 
ATOMFLAGS = -D_WIN32 -DWINDOWS -DATOM_STATIC  -static-libgcc -std=c++14 -static-libstdc++

SRC_DIR := src/core
OBJ_DIR := obj
LIB_DIR := lib

atom: $(OBJ_DIR)/vector3f.o

$(OBJ_DIR)/vector3f.o: $(SRC_DIR)/Vector3f.cpp
	$(CXX) -c $(SRC_DIR)/Vector3f.cpp -o $(OBJ_DIR)/vector3f.o

# atom: $(OBJ_DIR)/atom.o
	# $(CXX) $(CXXFLAGS) $(ATOMFLAGS) -o $(LIB_DIR)/atom.dll $(OBJ_DIR)/atom.o -lglut32 -lopengl32 -lglu32

# $(OBJ_DIR)/atom.o: $(SRC_DIR)/atom.cpp $(SRC_DIR)/atom.h
	# $(CXX) -c $(SRC_DIR)/atom.cpp -o $(OBJ_DIR)/atom.o

clean:
	rm obj *.o *~ 
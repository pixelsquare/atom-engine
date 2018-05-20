ALL: atom

CXX = g++
CXXFLAGS = -shared -g -Wall -Wfatal-errors
ATOMFLAGS = -D_USRDLL -static-libgcc -static-libstdc++

SRC_DIR := src/core
OBJ_DIR := obj
LIB_DIR := lib

atom: $(OBJ_DIR)/vector3f.o

$(OBJ_DIR)/vector3f.o: $(SRC_DIR)/Vector3f.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $(SRC_DIR)/Vector3f.cpp -o $(OBJ_DIR)/vector3f.o

clean:
	rm obj *.o *~ 
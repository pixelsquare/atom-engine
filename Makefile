CXX = g++ -std=c++11
CXXFLAGS = -shared -g -Wall -Wno-unknown-pragmas -fPIC -Wno-unused-function
ATOMFLAGS = -D_USRDLL -DATOM_STATIC -static-libgcc -static-libstdc++
GLFLAGS = -L/src/gl/glut32/lib -I/src/gl/glut32/include -DGLUT_NO_LIB_PRAGMA -lglut32 -lopengl32 -lglu32

SRC_DIR := src/core
OBJ_DIR := obj
LIB_DIR := lib
SRC_LIST = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

OBJS := $(wildcard $(OBJ_DIR:=/*.o))

build: $(OBJS)
	@echo Building atom library ...
	@echo
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) $(OBJS) -o $(LIB_DIR)/atom.dll
	@echo

compile: $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(wildcard $(SRC_DIR)/*.cpp)))))
	@echo

$(OBJ_DIR)/atom.o: $(SRC_DIR)/atom.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/Camera.o: $(SRC_DIR)/Camera.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/Collision.o: $(SRC_DIR)/Collision.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/Color3.o: $(SRC_DIR)/Color3.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/Color4.o: $(SRC_DIR)/Color4.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/GameObject.o: $(SRC_DIR)/GameObject.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/Input.o: $(SRC_DIR)/Input.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/Light.o: $(SRC_DIR)/Light.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/Mathf.o: $(SRC_DIR)/Mathf.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/Particle.o: $(SRC_DIR)/Particle.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/Physics.o: $(SRC_DIR)/Physics.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/Raycast.o: $(SRC_DIR)/Raycast.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/Sound.o: $(SRC_DIR)/Sound.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/Text.o: $(SRC_DIR)/Text.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/Time.o: $(SRC_DIR)/Time.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/Transform.o: $(SRC_DIR)/Transform.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/Vector3f.o: $(SRC_DIR)/Vector3f.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

clean:
	@echo Cleaning binary files ...
	rm -f $(OBJ_DIR)/*.o *~
	rm -f $(LIB_DIR)/*.* *~
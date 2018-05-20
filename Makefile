CXX = g++
CXXFLAGS = -shared -g -Wall -Wunknown-pragmas
ATOMFLAGS = -D_USRDLL -DATOM_STATIC -static-libgcc -static-libstdc++ -lglut32 -lopengl32 -lglu32

SRC_DIR := src/core
OBJ_DIR := obj
LIB_DIR := lib
SRC_LIST = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

OBJS := $(wildcard $(OBJ_DIR:=/*.o))

build: $(OBJS)
	@echo Building atom library ...
	@echo
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) $(OBJS) -o $(LIB_DIR)/atom.dll

compile: $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(wildcard $(SRC_DIR)/*.cpp)))))
	@echo

$(OBJ_DIR)/atom.o: $(SRC_DIR)/atom.cpp
$(OBJ_DIR)/Camera.o: $(SRC_DIR)/Camera.cpp
$(OBJ_DIR)/Collision.o: $(SRC_DIR)/Collision.cpp
$(OBJ_DIR)/GameObject.o: $(SRC_DIR)/GameObject.cpp
$(OBJ_DIR)/Input.o: $(SRC_DIR)/Input.cpp
$(OBJ_DIR)/Light.o: $(SRC_DIR)/Light.cpp
$(OBJ_DIR)/Particle.o: $(SRC_DIR)/Particle.cpp
$(OBJ_DIR)/Physics.o: $(SRC_DIR)/Physics.cpp
$(OBJ_DIR)/Raycast.o: $(SRC_DIR)/Raycast.cpp
$(OBJ_DIR)/Sound.o: $(SRC_DIR)/Sound.cpp
$(OBJ_DIR)/Text.o: $(SRC_DIR)/Text.cpp
$(OBJ_DIR)/Transform.o: $(SRC_DIR)/Transform.cpp

$(OBJ_DIR)/color3.o: $(SRC_DIR)/Color3.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/Color4.o: $(SRC_DIR)/Color4.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/Mathf.o: $(SRC_DIR)/Mathf.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

$(OBJ_DIR)/vector3f.o: $(SRC_DIR)/Vector3f.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ_DIR)/*.o *~
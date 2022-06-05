#CC specidies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies additional compilation options we're using
# -w suppresses all warnings
CXXFLAGS = -I./libs

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

# Source files directory
SRC_DIR := src

#BIN_DIR specifies where to put compiled binaries (.o)
BIN_DIR := bin

# Program library where .h modular library files exits
LIB_DIR := libs

#This is the target that compiles our excecutable
pathfinder : $(BIN_DIR)/Pathfinding.o $(BIN_DIR)/Renderer.o $(BIN_DIR)/Grid.o $(BIN_DIR)/Tree.o
	$(CC) -o $@ $^ $(LINKER_FLAGS)

$(BIN_DIR)/Pathfinding.o : $(SRC_DIR)/Pathfinding.cpp $(SRC_DIR)/Renderer.hpp $(SRC_DIR)/Grid.hpp
	$(CC) -c $(CXXFLAGS) $< -o $@

$(BIN_DIR)/Renderer.o : $(SRC_DIR)/Renderer.cpp $(SRC_DIR)/Renderer.hpp
	$(CC) -c $(CXXFLAGS) $< -o $@

$(BIN_DIR)/Grid.o : $(SRC_DIR)/Grid.cpp $(SRC_DIR)/Grid.hpp $(SRC_DIR)/Renderer.hpp
	$(CC) -c $(CXXFLAGS) $< -o $@

$(BIN_DIR)/Tree.o : $(SRC_DIR)/Tree.cpp $(SRC_DIR)/Tree.hpp $(LIB_DIR)/Common.hpp
	$(CC) -c $(CXXFLAGS) $< -o $@

.PHONY = clean

clean :
	rm -f pathfinder *.o
	rm $(BIN_DIR)/*

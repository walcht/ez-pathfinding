#CC specidies which compiler we're using
CC = g++

#SOURCE_DIR specifies source files directory
SOURCE_DIR = src/

#BIN_DIR specifies where to put compiled binaries
BIN_DIR = bin/

#COMPILER_FLAGS specifies additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -g

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#This is the target that compiles our excecutable
pathfinder : Pathfinding.o Renderer.o Grid.o Tree.o
	$(CC) $(COMPILER_FLAGS) -o $@ $^ $(LINKER_FLAGS)

Pathfinding.o: $(SOURCE_DIR)Pathfinding.cpp $(SOURCE_DIR)Renderer.hpp $(SOURCE_DIR)Grid.hpp
	$(CC) $(COMPILER_FLAGS) -c $<

Renderer.o: $(SOURCE_DIR)Renderer.cpp $(SOURCE_DIR)Renderer.hpp
	$(CC) $(COMPILER_FLAGS) -c $<

Grid.o: $(SOURCE_DIR)Grid.cpp $(SOURCE_DIR)Grid.hpp $(SOURCE_DIR)Renderer.hpp
	$(CC) $(COMPILER_FLAGS) -c $<

Tree.o: $(SOURCE_DIR)Tree.cpp $(SOURCE_DIR)Tree.hpp $(SOURCE_DIR)Common.hpp
	$(CC) $(COMPILER_FLAGS) -c $<

.PHONY = clean

clean :
	rm -f pathfinder *.o

# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -g
LDLIBS = -lGL -lGLU -lglut -lGLEW -lSDL2 -lSDL2_image -lfreetype

# Target name
TARGET = simulacrum
a:
	@echo "dsdss"
# Rule to build and run specifically for your testing file
simul: testing/simulacrum.cpp src/ball.cpp src/wall.cpp src/object.h src/ball.h
	$(CXX) $(CXXFLAGS) testing/simulacrum.cpp src/ball.cpp  -o $(TARGET) $(LDLIBS)
	./$(TARGET)


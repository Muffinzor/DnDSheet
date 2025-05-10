CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -O2
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = dndsheet

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

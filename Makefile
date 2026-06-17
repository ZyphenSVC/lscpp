CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

TARGET := lscpp
SRC := lscpp.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

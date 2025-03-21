# semplice file Make

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O1
SRC = main.cpp src/contatto.cpp src/list.cpp src/rubrica.cpp src/utils.cpp
TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

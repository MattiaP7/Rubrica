# semplice file Make

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
SRC = main.cpp src/contatto.cpp src/list.cpp src/rubrica.cpp
TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

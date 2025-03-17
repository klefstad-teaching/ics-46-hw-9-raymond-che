CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
SRC_DIR = src
TARGET = main

SOURCES = $(SRC_DIR)/dijkstras_main.cpp $(SRC_DIR)/dijkstras.cpp $(SRC_DIR)/ladder_main.cpp $(SRC_DIR)/ladder.cpp

main: $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	/bin/rm $(TARGET)
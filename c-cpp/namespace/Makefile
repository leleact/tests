CXX = g++
RM = rm -f 
CXXFLAGS = -std=c++11 -Wall -Wextra
ifdef DEBUG
	CXXFLAGS += -DDEBUG -g -O0
endif
SRC_DIR = src
BIN_DIR = bin
INC_DIR = include

TARGET = $(BIN_DIR)/namespace
SRC = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SRC))
ALL : clean $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I./$(INC_DIR) -I./$(SRC_DIR)

.PHONY : clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)

CXX = g++
RM = rm -f 
CXXFLAGS = -std=c++11 -Wall -Wextra
#ifdef DEBUG
	CXXFLAGS += -DDEBUG
#endif
SRC_DIR = src
BIN_DIR = bin
INC_DIR = include
LIB_DIR = 


TARGET = $(BIN_DIR)/sqlite3_test
SRC = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp)
LIB = -lsqlite3
OBJECTS = $(patsubst %.cpp,%.o,$(SRC))
ALL : clean $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@  $(LIB_DIR) $(LIB)

$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I./$(INC_DIR) -I./$(SRC_DIR)

.PHONY : clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)

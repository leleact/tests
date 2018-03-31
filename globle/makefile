
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra
RM = rm -f
INC_PATH = .
LIB_PATH = 

INCLUDES = -I$(INC_PATH)
LIBS = -lm -lpthread





TARGET = Main
OBJECTS = globleref1.o globleref2.o Main.o

all : clean $(TARGET)

$(TARGET) : $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LIBS) -o $@

$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY : clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)

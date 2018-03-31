CXX = g++
CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra
TARGET = lele_test_strchr
OBJECTS =	lele_test_strchr.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

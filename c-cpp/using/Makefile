CXX = /usr/local/bin/g++
RM = rm -f
CXXFLAGS = -std=c++11 -g
TARGET = lele_test_using
OBJECTS =	lele_test_using.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

CXX = g++ 
RM= rm -f
CXXFLAGS = -std=c++11 -g -Wall -O0


TARGET = lele_test_tinyxml2
OBJECTS= tinyxml2.o lele_test_tinyxml2.o


$(TARGET) : clean $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@
tinyxml2.o : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
ParseXml.o : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)

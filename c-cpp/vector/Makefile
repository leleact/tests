CXX = g++
RM = rm -f
CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra
TARGET = lele_test_vector
OBJECTS =	$(TARGET).o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@ $(PLATFORM_INCS) $(PLATFORM_LIBS) $(USE_SHARED_LIBS)
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(PLATFORM_INCS)
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

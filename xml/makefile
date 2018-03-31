CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra
TARGET = lele_test_xml
OBJECTS =	lele_test_xml.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@ $(PLATFORM_INCS) $(PLATFORM_LIBS) $(USE_SHARED_LIBS) -L../lib/ -lxml2
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(PLATFORM_INCS) -I../include/libxml2/
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

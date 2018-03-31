include /home/lele/platform/platmk/plat.mk

TARGET = lele_test_default
OBJECTS = lele_test_default.o

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean:
	$(RM) $(TARGET) $(OBJECTS)

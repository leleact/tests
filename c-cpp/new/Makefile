include ~/platform/platmk/plat.mk
TARGET = lele_test_new
OBJECTS =	lele_test_new.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

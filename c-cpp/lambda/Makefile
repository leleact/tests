include ~/platform/platmk/plat.mk
TARGET = lele_test_lambda
OBJECTS =	lele_test_lambda.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

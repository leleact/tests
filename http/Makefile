include ~/platform/platmk/plat.mk
TARGET = lele_test_http
OBJECTS =	lele_test_http.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -g -o $@
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -g -c $< -o $@
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

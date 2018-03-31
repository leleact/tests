include ~/platform/platmk/plat.mk
all :	lele_test_decltype
lele_test_decltype = lele_test_decltype
objects =	lele_test_decltype.o
$(lele_test_decltype) : $(objects)
	$(CXX) $(CXXFLAGS) $< -o $@
$(objects) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY : clean
clean:
	$(RM) $(objects) $(lele_test_decltype)

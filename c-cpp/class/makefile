include ~/make/plat.mak
TARGET = lele_test_class
OBJECTS = lele_test_class.o obstract.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(PLATFORM_INCS) $(PLATFORM_LIBS) $(USE_SHARED_LIBS)
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(PLATFORM_INCS)
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

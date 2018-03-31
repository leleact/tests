include ~/make/plat.mak
TARGET = lele_test_pthread_mutex
OBJECTS =	$(TARGET).o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@ $(PLATFORM_INCS) $(PLATFORM_LIBS) $(USE_SHARED_LIBS)
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(PLATFORM_INCS)
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

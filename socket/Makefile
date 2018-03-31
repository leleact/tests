include ~/make/plat.mak
TARGET = lele_test_client lele_test_server
OBJECTS =	lele_test_client.o lele_test_server.o
all : $(TARGET)

lele_test_client : lele_test_client.o 
	$(CXX) $(CXXFLAGS) $< -o $@ $(PLATFORM_INCS) $(PLATFORM_LIBS) $(USE_SHARED_LIBS)

lele_test_server : lele_test_server.o 
	$(CXX) $(CXXFLAGS) $< -o $@ $(PLATFORM_INCS) $(PLATFORM_LIBS) $(USE_SHARED_LIBS)

$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(PLATFORM_INCS)
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

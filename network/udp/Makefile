CXX = g++
CC = gcc
CPPFLAG=-std=c++11
TARGETS=server client server_new client_new

.PHONY: All clean

All : server client server_new client_new

server: server.cpp
	$(CXX) $(CPPFLAG) $^ -o $@

client: client.cpp
	$(CXX) $(CPPFLAG) $^ -o $@

server_new: server_new.cpp socket.cpp
	$(CXX) $(CPPFLAG) $^ -o $@

client_new: client_new.cpp socket.cpp
	$(CXX) $(CPPFLAG) $^ -o $@


clean:
	rm -f $(TARGETS)

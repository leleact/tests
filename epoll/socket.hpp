#ifndef _VARLIB_SOCKET_H
#define _VARLIB_SOCKET_H

#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include "socketException.hpp"

namespace varlib {
class socket {
public:
	enum PROTROL {
		TCPv4 = AF_INET 
	};
public:
	socket(const char *IPAddr, short port, PROTROL protrol) throw(varlib::socketException)
		: m_IPAddr(IPAddr), m_port(port), m_protrol(protrol), m_socket_id(-1) {
		int ret = ::socket(protrol, SOCK_STREAM, 0);
		if (ret <= 0 ) {
			throw varlib::socketException(errno);
		}
		m_socket_id = ret;
	}
	int getSocket() { return m_socket_id; };

private:
	std::string m_IPAddr;	
	short m_port;
	PROTROL m_protrol;
	int m_socket_id;
};

class serverSocket : public socket {
public:
	serverSocket(const char *IPAddr, short port, PROTROL protrol) : socket(IPAddr, port, protrol) {}
};
}
#endif

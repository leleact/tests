#ifndef _VARLIB_SOCKET_EXCEPTION_H
#define _VARLIB_SOCKET_EXCEPTION_H
#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <errno.h>
#include <string.h>

namespace varlib {

class socketException : public std::exception {
public:
	socketException(int error) :m_errno(error) { }

	virtual const char *what() noexcept {
		std::ostringstream os;
		os << "errno: " << m_errno << ", " << strerror(m_errno);	
		m_errmsg = os.str();
		return m_errmsg.c_str();
	}
private:
	int m_errno;
	std::string m_errmsg;
};
}
#endif

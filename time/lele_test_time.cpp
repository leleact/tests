#include <iostream>
#include <iomanip>
#include <time.h>
#include <sys/time.h>

int main()
{
	struct timeval tv;	
	struct timezone tz;
	gettimeofday(&tv, &tz);

	struct tm *tm_now = localtime(&tv.tv_sec);

	std::cout << "[" << std::setw(4) << tm_now->tm_year + 1900		<< "-" 
		<< std::setfill('0') << std::setw(2) << tm_now->tm_mon + 1  << "-" 
		<< std::setfill('0') << std::setw(2) << tm_now->tm_mday		<< " " 
		<< std::setfill('0') << std::setw(2) << tm_now->tm_hour		<< ":" 
		<< std::setfill('0') << std::setw(2) << tm_now->tm_min		<< ":" 
		<< std::setfill('0') << std::setw(2) << tm_now->tm_sec		<< " " 
		<< std::setfill('0') << std::setw(6) << tv.tv_usec << "]" << std::endl;
	return 0;
}

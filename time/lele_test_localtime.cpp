
#include <iostream>
#include <time.h>
#include <sys/time.h>

void run(long nCount);

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::cerr << "Please Use ... <count>" << std::endl;

	run(atol(argv[1]));
	return 0;
}

void run(long nCount)
{
	struct timeval starttime;
	struct timeval endtime;
	long lCount = 0;

	gettimeofday(&starttime, NULL);
	while(true)
	{
		if (lCount > nCount)
			break;
		lCount++;
	}
	gettimeofday(&endtime, NULL);

	long difftime = 1000000 * (endtime.tv_sec - starttime.tv_sec) + (endtime.tv_usec - starttime.tv_usec);
	std::cout << "starttime.tv_sec:"  << starttime.tv_sec  << "\n" 
		      << "starttime.tv_usec:" << starttime.tv_usec << "\n"
		      << "endtime.tv_sec:"    << endtime.tv_sec    << "\n" 
		      << "endtime.tv_usec:"   << endtime.tv_usec   << "\n"
		      << "difftime:"          << difftime <<       std::endl;

	char formatStartTime[100] = {0};
	char formatEndTime[100]   = {0};
	struct tm *start_tm = localtime(&starttime.tv_sec);
	strftime(formatStartTime, sizeof(formatStartTime), "%Y-%m-%d %H:%M:%S", start_tm);
	std::cout << "start@" << formatStartTime << "." << starttime.tv_usec << std::endl;

	struct tm *end_tm = localtime(&endtime.tv_sec);
	strftime(formatEndTime, sizeof(formatEndTime), "%Y-%m-%d %H:%M:%S", end_tm);
	std::cout << "end@" << formatEndTime << "." << endtime.tv_usec << std::endl;

	std::cout << static_cast<long>(difftime/1000000) << "." << static_cast<long>(difftime % 1000000) << std::endl;
	return ;
}

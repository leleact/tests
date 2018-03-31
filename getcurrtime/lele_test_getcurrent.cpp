#include <stdio.h>
#include <string.h>

void getcurrtime(char *);

int main()
{
	char strtime[26 + 1];
	memset(strtime, 0, sizeof(strtime));
	getcurrtime(strtime);
	fprintf(stdout, "current time is [%s]\n", strtime);
}

#include <sys/time.h>
#include <time.h>
void getcurrtime(char *strtime) {
	struct timeval t_time;
	gettimeofday(&t_time, NULL);

	struct tm *tm_now;
	time_t now;
	now = t_time.tv_sec;
	tm_now = localtime(&now);

	sprintf(strtime, "%04d-%02d-%02d %02d:%02d:%02d:%ld", tm_now->tm_year + 1900, \
			tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec, t_time.tv_usec);

}

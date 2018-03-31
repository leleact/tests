#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
typedef struct
{
	long lcount;
	std::mutex lmutex;
} data;
data d;
void task(std::string no)
{
	while(1)
	{
		usleep(100);
		d.lmutex.lock();
		if ( d.lcount <= 0 )
		{
			d.lmutex.unlock();
			break;	
		}
		d.lcount--;
		std::cout << "no: " << no << " count[" << d.lcount << "]" << std::endl;
		d.lmutex.unlock();
	}
}

int main(int argc, char *argv[])
{
	d.lcount = 1000000;
	std::thread t1(task, "task1");
	std::thread t2(task, "task2");
	t1.join();
	t2.join();
	return 0;
}

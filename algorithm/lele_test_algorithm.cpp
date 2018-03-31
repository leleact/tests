#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <time.h>
#include <sys/time.h>
using namespace std;

void bubble_sort(int *, int);
void printf_array(int *, int);
void swap(int *, int *);
void writetofile(int *, int, char *);
void insert_sort_des(int *, int);

#define MAXLEN 10000
#define CYCTIMES 1

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Please use: main <outFileName1> <outFileName2>" << std::endl;	
		return 1;
	}
	char outFileName1[256];
	char outFileName2[256];
	memset(outFileName1, 0x00, sizeof(outFileName1));
	memset(outFileName2, 0x00, sizeof(outFileName2));
	strcpy(outFileName1, argv[1]);
	strcpy(outFileName2, argv[2]);
	struct timeval start, end;
	int Testarray[MAXLEN];
	for (int i = 0; i < MAXLEN; i++)
		Testarray[i] = i;

	srand(time(NULL));
	for (int i = MAXLEN - 1; i > 0;  --i) {
		int index = rand() % i;	
		swap(Testarray + i, Testarray + index);
	}

	writetofile(Testarray, MAXLEN, outFileName1);
	gettimeofday(&start, NULL);
	for (int i = 0; i < CYCTIMES; ++i) {
		bubble_sort(Testarray, MAXLEN);
	}
	gettimeofday(&end, NULL);
	writetofile(Testarray, MAXLEN, outFileName2);
	cout << setprecision(6) << end.tv_sec - start.tv_sec + (double)(end.tv_usec - start.tv_usec)/1000000 << endl;
}

void bubble_sort(int *array, int n) {
	for(int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j)	{
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void printf_array(int *array, int n) {
	for (int i = 0; i < n; i++) {
		printf("array[%d] = [%d]\n", i, array[i]);
	}
}

void swap(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

void writetofile(int *array, int n, char *str) {
	fstream file;
	file.open(str, fstream::out | fstream::trunc);
	for (int i = 0; i < n; ++i) {
		file << setw(4) << array[i] << " ";
		if ( (i + 1) % 16 == 0) file << "\n";
	}

	file.close();
}

void insert_sort_des(int *array, int n) {
	for (int i = 1; i < n; ++i) {
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}

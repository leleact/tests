#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
using namespace std;

template<typename T, size_t arr_size>
void MaxHeapIfy(T (&)[arr_size], int, int);

template<typename T, size_t arr_size>
void BuildMaxHeap(T (&)[arr_size]);

template<typename T, size_t arr_size>
void HeapSort(T (&)[arr_size], int);

template<typename T, size_t arr_size>
void PrintArr(T (&)[arr_size]);

int main(int argc, char **argv) {
  /*
  if (argc != 3) {
    cout << "Please Use : Heap_sort <Filename1> <Filename2>" << endl;
    exit(1);
  }

  string filename1(*(argv + 1));
  string filename2(*(argv + 2));
  */

  const int arr_size = 30;
  int arr[arr_size];
  for (int i = 0; i < arr_size; ++i) {
    arr[i] = i;
  }

  srand(time(nullptr));
  int index = 0;
  for (int i = arr_size - 1; i > 0; --i) {
    index = rand() % i; 
    swap(arr[index], arr[i]);
  }

  PrintArr(arr);
  HeapSort(arr, arr_size);
  PrintArr(arr);

  return 0;
}

template<typename T, size_t arr_size>
void MaxHeapIfy(T (&arr)[arr_size], int i, int heap_size) {
  int left_child = 2 * i + 1;
  int right_child = 2 * i + 2;

  if (left_child >= heap_size && right_child >= heap_size)
    return;

  int max = i;
  if (arr[left_child] > arr[i] && left_child < heap_size)
    max = left_child;
  else max = i;

  if (arr[right_child] > arr[max] && right_child < heap_size)
    max = right_child;

  if (max != i) {
    swap(arr[i], arr[max]); 
    MaxHeapIfy(arr, max, heap_size);
  }
}

template<typename T, size_t arr_size>
void BuildMaxHeap(T (&arr)[arr_size]) {
  int temp = arr_size / 2 - 1; 
  for (int i = temp; i >= 0; --i) {
    MaxHeapIfy(arr, i, arr_size);
  }
}

template<typename T, size_t arr_size>
void HeapSort(T (&arr)[arr_size], int heap_size) {
#ifdef DEBUG
  cout << "BuildMaxHeap start" << endl;
  PrintArr(arr);
#endif
  BuildMaxHeap(arr);
#ifdef DEBUG
  PrintArr(arr);
  cout << "BuildMaxHeap finished" << endl;
#endif
  for (int i = arr_size - 1; i > 0; --i) {
    swap(arr[0], arr[i]);
    --heap_size;
    MaxHeapIfy(arr, 0, heap_size);
  }
}

template<typename T, size_t arr_size>
void PrintArr(T (&arr)[arr_size]) {
  for (size_t i = 0; i < arr_size; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

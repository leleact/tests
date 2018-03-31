#include <iostream>
#include <climits>
using namespace std;
template<typename T, size_t arr_size>
void Merge(T (&)[arr_size], int, int, int);

template<typename T, size_t arr_size>
void MergeSort(T (&)[arr_size], int, int);

template<typename T, size_t arr_size>
void PrintArr(T (&)[arr_size], int, int);

int g_T_max = (1 << 31) - 1;

int main() {
  const int kmaxsize = 255;
  int arr[kmaxsize];
  for (int i = 0; i < kmaxsize; ++i) {
    arr[i] = i;
  }

  srand(time(nullptr));
  int index;
  for (int i = kmaxsize - 1; i > 0; --i) {
    index = rand() % i; 
    swap(arr[i], arr[index]);
  }

  PrintArr(arr, 0, kmaxsize - 1);
  MergeSort(arr, 0, kmaxsize - 1);
  PrintArr(arr, 0, kmaxsize - 1);

  return 0;
}


template<typename T, size_t arr_size>
void Merge(T (&arr)[arr_size], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  T left_arr[n1 + 1];
  T right_arr[n2 + 1];

  for (int i = 0; i < n1; ++i) {
    left_arr[i] = arr[p + i];
  }

  for (int i = 0; i < n2; ++i) {
    right_arr[i]  = arr[q + i + 1];
  }

  left_arr[n1] = g_T_max;
  right_arr[n2] = g_T_max;

  int i = 0;
  int j = 0;
  for (int k = p; k <= r; ++k) {
    if (left_arr[i] <= right_arr[j]) {
      arr[k] = left_arr[i];
      ++i;
    } else {
      arr[k] = right_arr[j];
      ++j;
    }
  }
}

template<typename T, size_t arr_size>
void MergeSort(T (&arr)[arr_size], int p, int r) {
  if (p < r) {
    int q = p + (r - p) / 2;
    MergeSort(arr, p, q); 
    MergeSort(arr, q + 1, r); 
    Merge(arr, p, q , r);
  }
}

template<typename T, size_t arr_size>
void PrintArr(T (&arr)[arr_size], int p, int r) {
  for (int i = p; i < r + 1; ++i) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

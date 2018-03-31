#include <iostream>

template <typename T>
void QuickSort(T *array, size_t size) {
	if (array == NULL) {
		return;	
	}

	if (size == 0 || size == 1) {
		return;	
	}
	size_t i = 0;
	size_t j = size - 1;
	T certValue = array[0];

}

template <typename T>
void Swap(T *a, T *b) {
	T value = *a;
	*a = *b;
	*b = value;
	return ;
}

int main(int argc, char *argv[]) {
	int x = 10;
	int y = 15;
	Swap(&x, &y);
	std::cout << x << y << std::endl;
	return 0;
}

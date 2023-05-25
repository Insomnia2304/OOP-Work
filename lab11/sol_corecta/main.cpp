#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T a[], int size, bool Ascending = 1) {
	bool ok = 1;
	while (ok) {
		ok = 0;
		for (int i = 0; i < size - 1; i++)
			if (Ascending == 1 && a[i] > a[i + 1] ||
				Ascending == 0 && a[i] < a[i + 1]) {
				swap(a[i], a[i + 1]);
				ok = 1;
			}
	}
}

template <typename T>
void printArray(T a[], int size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	int a[] = { 8, 5, 10, 0, -3, 4, 0, 90, 1 };
	bubbleSort(a, 9, 0);
	printArray(a, 9);

	bubbleSort(a, 9, 1);
	printArray(a, 9);
	return 0;
}
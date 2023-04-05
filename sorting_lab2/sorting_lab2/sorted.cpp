#include <iostream>
#include <vector>
#include <random>
using namespace std;
void fill_random(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100 + 1;
	}
}
void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "[" << i << "] = " << arr[i] << endl;
	}
	cout << endl;
}

void selection_sort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}
		int tmp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
	}
}
void selection_sort(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		int min_index = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}
		int tmp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
	}
}

void Quick_sort(int* arr, int n) {
	int i = 0;
	int j = n - 1;
	int mid = arr[n / 2];
	do {
		while (arr[i] < mid) {
			i++;
		}
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);


	if (i < n) {
		Quick_sort(&arr[i], n - i);
	}
	if (j > 0) {
		Quick_sort(arr, j + 1);
	}
}

int main() {
	int n = 5;
	cout << "Selection sort\n\n";
	int* arr = new int[n];
	cout << "source array:\n";
	fill_random(arr, n);
	print(arr, n);
	selection_sort(arr, n);
	cout << "Sorted array:\n";
	print(arr, n);

	cout << "\n\nQuick sort\n\n";
	int* arr2 = new int[n];
	cout << "source array:\n";
	fill_random(arr2, n);
	print(arr2, n);
	Quick_sort(arr2, n);
	cout << "Sorted array:\n";
	print(arr2, n);
}
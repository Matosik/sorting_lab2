#include <iostream>
using namespace std;

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

void fill_random(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = lcg();
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

void sort() {
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
void selection_sort(int* arr, int n, long long* result) {

	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			result[0] += 1;
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}
		int tmp = arr[i];
		result[1] += 1;
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
	}
}
void Quick_sort(int* arr, int n, long long* result) {
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
void test_selection_sort(int n) {
	setlocale(LC_ALL, "ru");
	long long counter_copy = 0;
	long long counter_comparison = 0;
	long long result[2] = { 0,0 };
	for (int i = 0; i < 100; i++) {
		result[0] = 0;
		result[1] = 0;
		int* arr = new int[n];
		fill_random(arr, n);
		selection_sort(arr, n, result);
		counter_comparison += result[0];
		counter_copy += result[1];
	}
	cout << n <<"  �������� � ������� - ���������� ���������: " << counter_comparison / 100 << "\t���������� ����������� ��������: " << counter_copy / 100;
}

void test_quick_sort(int n) {
	long long counter_copy = 0;
	long long counter_comparison = 0;
	long long result[2] = { 0,0 };
	for (int i = 0; i < 100; i++) {
		result[0] = 0;
		result[1] = 0;
		int* arr = new int[n];
		fill_random(arr, n);
		Quick_sort(arr, n, result);
		counter_comparison += result[0];
		counter_copy += result[1];
	}
	cout << n << "  �������� � ������� - ���������� ���������: " << counter_comparison / 100 << "\t���������� ����������� ��������: " << counter_copy / 100;
}



int main() {
	setlocale(LC_ALL, "ru");
	for (int i = 1000; i <= 10000; i += 1000) {
		test_selection_sort(i);
		cout << endl;
	}
	test_selection_sort(25000);
	cout << endl;
	test_selection_sort(50000);
	cout << endl;
	test_selection_sort(100000);
	cout << endl;
}

//1000  �������� � ������� - ���������� ��������� : 499500 ���������� ����������� �������� : 1000
//2000  �������� � ������� - ���������� ��������� : 1999000        ���������� ����������� �������� : 2000
//3000  �������� � ������� - ���������� ��������� : 4498500        ���������� ����������� �������� : 3000
//4000  �������� � ������� - ���������� ��������� : 7998000        ���������� ����������� �������� : 4000
//5000  �������� � ������� - ���������� ��������� : 12497500       ���������� ����������� �������� : 5000
//6000  �������� � ������� - ���������� ��������� : 17997000       ���������� ����������� �������� : 6000
//7000  �������� � ������� - ���������� ��������� : 24496500       ���������� ����������� �������� : 7000
//8000  �������� � ������� - ���������� ��������� : 31996000       ���������� ����������� �������� : 8000
//9000  �������� � ������� - ���������� ��������� : 40495500       ���������� ����������� �������� : 9000
//10000  �������� � ������� - ���������� ��������� : 49995000      ���������� ����������� �������� : 10000
//25000  �������� � ������� - ���������� ��������� : 312487500     ���������� ����������� �������� : 25000
//50000  �������� � ������� - ���������� ��������� : 1249975000    ���������� ����������� �������� : 50000
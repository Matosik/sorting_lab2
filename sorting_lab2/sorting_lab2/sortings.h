#pragma once
//standart sorting
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

//sorting for test
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
void Quick_sort(int* arr, int n, int* result) {
	int i = 0;
	int j = n - 1;
	int mid = arr[n / 2];
	result[1] ++;
	do {
		result[0]++;
		while (arr[i] < mid) {
			i++;
		}
		result[0]++;
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			int tmp = arr[i];
			result[1] ++;
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);


	if (i < n) {
		Quick_sort(&arr[i], n - i, result);
	}
	if (j > 0) {
		Quick_sort(arr, j + 1, result);
	}
}
#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;
//standart sorting

void selection_sort(vector<int>  &arr) {
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

void Quick_sort(vector <int> &arr, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	if (left < j)
		Quick_sort(arr, left, j);
	if (i < right)
		Quick_sort(arr, i, right);
}

//sorting for test
void selection_sort(vector<int> &arr, stats &result) {
	for (int i = 0; i < arr.size(); i++) {
		int min_index = i;
		for (int j = i + 1; j < arr.size(); j++) {
			result.comparison_count += 1;
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}
		int tmp = arr[i];
		result.copy_count += 1;
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
	}
}
void Quick_sort(vector <int>& arr, int left, int right, stats &result) {
	int i = left;
	int j = right;
	int pivot = arr[(left + right) / 2];
	while (i <= j) {
		result.comparison_count += 1;
		while (arr[i] < pivot)
			i++;
		result.comparison_count += 1;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			result.copy_count += 1;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	if (left < j)
		Quick_sort(arr, left, j, result);
	if (i < right)
		Quick_sort(arr, i, right, result);
}

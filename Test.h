#pragma once
#include "sortings.h"
size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}
void fill_random(vector<int>& arr, int n) {
	for (int i = 0; i < n; i++) {
		arr.push_back(lcg());
	}
}
//random
void test_random_selection_sort(int n) {
	size_t counter_copy = 0;
	size_t counter_comparison = 0;
	stats result;
	for (int i = 0; i < 100; i++) {
		result.comparison_count = 0;
		result.copy_count = 0;
		vector<int>arr;
		fill_random(arr, n);
		selection_sort(arr, result);
		counter_comparison += result.comparison_count;
		counter_copy += result.copy_count;
	}
	cout << n << " Values in array - Number of comparisons: " << counter_comparison / 100 << "\tNumber of copying objects: " << counter_copy / 100;
}

void test_random_quick_sort(int n) {
	size_t counter_copy = 0;
	size_t counter_comparison = 0;
	stats result;
	for (int i = 0; i < 100; i++) {
		result.comparison_count = 0;
		result.copy_count = 0;
		vector<int> arr;
		fill_random(arr, n);
		Quick_sort(arr, 0, arr.size() - 1, result);
		counter_comparison += result.comparison_count;
		counter_copy += result.copy_count;
	}
	cout << n << " Values in array - Number of comparisons: " << counter_comparison / 100 << "\tNumber of copying objects: " << counter_copy / 100;
}


void test_random() {
	system("cls");
	cout << "Test Quick sort:" << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_random_quick_sort(i);
		cout << endl;
	}
	test_random_quick_sort(25000);
	cout << endl;
	test_random_quick_sort(50000);
	cout << endl;
	test_random_quick_sort(100000);
	cout << endl;
	cout << "\n\nTest_selection_sort:" << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_random_selection_sort(i);
		cout << endl;
	}
	//test_random_selection_sort(25000);
	cout << endl;
	//test_random_selection_sort(50000);
	cout << endl;
	//test_random_selection_sort(100000);
	cout << endl;
	next_programm();
}
//sorted array
void test_sorted_array_selection(int n) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(i);
	}
	stats result;
	selection_sort(arr, result);
	cout << n << "Values in array - Number of comparisons: " << result.comparison_count << "\tNumber of copying objects: " << result.copy_count;
}

void test_sorted_array_quick(int n) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(i);
	}
	stats result;
	Quick_sort(arr, 0, n - 1, result);
	cout << n << "Values in array - Number of comparisons: " << result.comparison_count << "\tNumber of copying objects: " << result.copy_count;
}

void test_sorted_array() {
	system("cls");
	cout << "Test sorted array Quick: " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_sorted_array_quick(i);
		cout << endl;
	}
	test_sorted_array_quick(25000);
	cout << endl;
	test_sorted_array_quick(50000);
	cout << endl;
	test_sorted_array_quick(100000);
	cout << "\n\n";

	cout << "Test sorted array Selection: " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_sorted_array_selection(i);
		cout << endl;
	}
	//test_sorted_array_selection(25000);
	cout << endl;
	//test_sorted_array_selection(50000);
	cout << endl;
	//test_sorted_array_selection(100000);

	next_programm();
}
//reverse sorted 

void test_reverse_sorted_array_selection(int n) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(n - i);
	}
	stats result;
	selection_sort(arr, result);
	cout << n << " Values in array - Number of comparisons: " << result.comparison_count << "\t   Number of copying objects: " << result.copy_count;
}
void test_reverse_sorted_array_quick(int n) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(n - i);
	}
	stats result;
	Quick_sort(arr, 0, n - 1, result);
	cout << n << " Values in array - Number of comparisons: " << result.comparison_count << "\t   Number of copying objects: " << result.copy_count;
}

void test_reverse_sorted_array() {
	system("cls");
	cout << "Test reverse sorted array  Quick: " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_reverse_sorted_array_quick(i);
		cout << endl;
	}
	test_reverse_sorted_array_quick(25000);
	cout << endl;
	test_reverse_sorted_array_quick(50000);
	cout << endl;
	test_reverse_sorted_array_quick(100000);
	cout << "\n\n";


	cout << "Test reverse sorted array  Selection: " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_reverse_sorted_array_selection(i);
		cout << endl;
	}
	//test_reverse_sorted_array_selection(25000);
	cout << endl;
	//test_reverse_sorted_array_selection(50000);
	cout << endl;
	//test_reverse_sorted_array_selection(100000);
	next_programm();
}

//speed
void speed_quick(int n) {
	float result = 0;
	for (int i = 0; i < 100; i++) {
		vector<int> arr;
		fill_random(arr, n);
		auto start = chrono::high_resolution_clock::now();
		Quick_sort(arr, 0, n - 1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> time = (end - start);
		result += time.count();
	}
	cout << n << " -  Values in array. Time Quick sort - " << result/100 << endl;
}
void speed_selection(int n) {
	float result = 0;
	for (int i = 0; i < 100; i++) {
		vector<int> arr;
		fill_random(arr, n);
		auto start = chrono::high_resolution_clock::now();
		selection_sort(arr);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> time = end - start;
		result += time.count();
	}
	cout << n << " -  Values in array. Time Selection sort - " << result/100 << endl;
}

void speed_test() {
	system("cls");
	cout << "Quick sort:" << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		speed_quick(i);
	}
	speed_quick(25000);
	speed_quick(50000);
	speed_quick(100000);
	cout << endl << endl;
	cout << "Selection sort:" << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		speed_selection(i);
	}
	speed_selection(25000);
	speed_selection(50000);
	speed_selection(100000);
	next_programm();
}

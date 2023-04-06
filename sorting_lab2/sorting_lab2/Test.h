#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "sortings.h"
using namespace std;

void next_programm() {
	cout << "\n\n\t\t\t\tPress any key to continue";
	_getch();
}

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
//random
void test_random_selection_sort(int n) {
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
		delete[] arr;
	}
	cout << n << " Values in array - Number of comparisons: " << counter_comparison / 100 << "\tNumber of copying objects: " << counter_copy / 100;
}

void test_random_quick_sort(int n) {
	int counter_copy = 0;
	int counter_comparison = 0;
	int result[2] = { 0,0 };
	for (int i = 0; i < 100; i++) {
		result[0] = 0;
		result[1] = 0;
		int* arr = new int[n];
		fill_random(arr, n);
		Quick_sort(arr, n, result);
		counter_comparison += result[0];
		counter_copy += result[1];
		delete[] arr;
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
	next_programm();
	//cout << "\n\nTest_selection_sort:" << endl;
	//for (int i = 1000; i <= 10000; i += 1000) {
	//	test_random_selection_sort(i);
	//	cout << endl;
	//}
	//test_random_selection_sort(25000);
	//cout << endl;
	//test_random_selection_sort(50000);
	//cout << endl;
	//test_random_selection_sort(100000);
	//cout << endl;
	//next_programm();
}

//sorted
void test_sorted_array_selection(int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	long long result[2] = { 0,0 };
	selection_sort(arr, n ,result);
	cout << n << "Values in array - Number of comparisons: " << result[0] << "\tNumber of copying objects: " << result[1];
}

void test_sorted_array_quick(int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	int result[2] = { 0,0 };
	Quick_sort(arr, n, result);
	cout << n << "Values in array - Number of comparisons: " << result[0] << "\tNumber of copying objects: " << result[1];
}

void test_sorted_array() {
	system("cls");
	cout << "test_sorted_array - Selection: "<<endl;
	for (int i = 1000; i <= 10000; i+=1000) {
		test_sorted_array_selection(i);
		cout << endl;
	}
	test_sorted_array_selection(25000);
	cout << endl;
	test_sorted_array_selection(50000);
	cout << endl;
	test_sorted_array_selection(100000);
	cout << "\n\n";

	cout << "test_sorted_array - Quick: " << endl;
	for (int i = 0; i <= 10000; i += 1000) {
		test_sorted_array_quick(i);
		cout << endl;
	}
	test_sorted_array_quick(25000);
	cout << endl;
	test_sorted_array_quick(50000);
	cout << endl;
	test_sorted_array_quick(100000);
	next_programm();
}
//reverse sorted 

void test_reverse_sorted_array_selection(int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = n-i;
	}
	long long result[2] = { 0,0 };
	selection_sort(arr, n, result);
	cout << n << "Values in array - Number of comparisons: " << result[0] << "\tNumber of copying objects: " << result[1];
}
void test_reverse_sorted_array_quick(int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = n - i;
	}
	int result[2] = { 0,0 };
	Quick_sort(arr, n, result);
	cout << n << "Values in array - Number of comparisons: " << result[0] << "\tNumber of copying objects: " << result[1];
}

void test_reverse_sorted_array() {
	system("cls");
	cout << "test_reverse_sorted_array - Selection: " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_reverse_sorted_array_selection(i);
		cout << endl;
	}
	test_reverse_sorted_array_selection(25000);
	cout << endl;
	test_reverse_sorted_array_selection(50000);
	cout << endl;
	test_reverse_sorted_array_selection(100000);
	cout << "\n\n";

	cout << "test_reverse_sorted_array - Quick: " << endl;
	for (int i = 1000; i <= 10000; i += 1000) {
		test_reverse_sorted_array_quick(i);
		cout << endl;
	}
	test_reverse_sorted_array_quick(25000);
	cout << endl;
	test_reverse_sorted_array_quick(50000);
	cout << endl;
	test_reverse_sorted_array_quick(100000);
	next_programm();
}
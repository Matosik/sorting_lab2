#include <iostream>
#include "Test.h"
using namespace std;
//standart sorting


void print(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sort() {
	system("cls");
	int n = 5;
	cout << "Selection sort\n\n";
	vector<int> arr;
	cout << "source array:\n";
	fill_random(arr, n);
	print(arr);
	selection_sort(arr);
	cout << "Sorted array:\n";
	print(arr);

	cout << "\n\nQuick sort\n\n";
	vector<int> arr2;
	cout << "source array:\n";
	fill_random(arr2, n);
	print(arr2);
	Quick_sort(arr2, 0,n-1);
	cout << "Sorted array:\n";
	print(arr2);
	next_programm();
}
int menu() {
	int key;
	while (true) {
		system("cls");
		cout << "\n\tTest random arrays        - [ 1 ]";
		cout << "\n\tTest sorted arrays        - [ 2 ]";
		cout << "\n\tTest reverse sorted array - [ 3 ]";
		cout << "\n\tCheck sort                - [ 4 ]";
		cout << "\n\tTime sorting              - [ 5 ]";
		cout << "\n\tExit                      - [esc]";
		key = _getch();
		if (key == 27 || key == 49 || key == 50|| key ==51|| key==52|| key ==53) { return key; }
	}
}

int main() {
	setlocale(LC_ALL, "ru");
Menu:
	system("cls");
	int menu_ = menu();
	switch (menu_)
	{
	case 49:
		test_random();
		goto Menu;
	case 50:
		test_sorted_array();
		goto Menu;
	case 51:
		test_reverse_sorted_array();
		goto Menu;
	case 52:
		sort();
		goto Menu;
	case 53:
		speed_test();
		goto Menu;
	case 27:
		break;
	}
}
//======RANDOM======
//Test Quick sort :
//1000   Values in array - Number of comparisons : 6329      Number of copying objects : 4070
//2000   Values in array - Number of comparisons : 13640     Number of copying objects : 8631
//3000   Values in array - Number of comparisons : 21247     Number of copying objects : 13348
//4000   Values in array - Number of comparisons : 29067     Number of copying objects : 18164
//5000   Values in array - Number of comparisons : 37102     Number of copying objects : 23081
//6000   Values in array - Number of comparisons : 45273     Number of copying objects : 28078
//7000   Values in array - Number of comparisons : 53500     Number of copying objects : 33102
//8000   Values in array - Number of comparisons : 61876     Number of copying objects : 38197
//9000   Values in array - Number of comparisons : 70336     Number of copying objects : 43331
//10000  Values in array - Number of comparisons : 78894     Number of copying objects : 48526
//25000  Values in array - Number of comparisons : 212234    Number of copying objects : 128796
//50000  Values in array - Number of comparisons : 447863    Number of copying objects : 269289
//100000 Values in array - Number of comparisons : 941952    Number of copying objects : 561705


//Testselection_sort :
//1000		Values in array - Number of comparisons : 499500	 Number of copying objects : 1000
//2000		Values in array - Number of comparisons : 1999000    Number of copying objects : 2000
//3000		Values in array - Number of comparisons : 4498500    Number of copying objects : 3000
//4000		Values in array - Number of comparisons : 7998000    Number of copying objects : 4000
//5000		Values in array - Number of comparisons : 12497500   Number of copying objects : 5000
//6000		Values in array - Number of comparisons : 17997000   Number of copying objects : 6000
//7000		Values in array - Number of comparisons : 24496500   Number of copying objects : 7000
//8000		Values in array - Number of comparisons : 31996000   Number of copying objects : 8000
//9000		Values in array - Number of comparisons : 40495500   Number of copying objects : 9000
//10000		Values in array - Number of comparisons : 49995000   Number of copying objects : 10000
//25000		Values in array - Number of comparisons : 312487500  Number of copying objects : 25000
//50000		Values in array - Number of comparisons : 1249975000 Number of copying objects : 50000
//100000	Values in array - Number of comparisons : 499950000  Number of copying objects : 100000

//======SORTED=======

//1000Values in array - Number of comparisons : 499500     Number of copying objects : 1000
//2000Values in array - Number of comparisons : 1999000    Number of copying objects : 2000
//3000Values in array - Number of comparisons : 4498500    Number of copying objects : 3000
//4000Values in array - Number of comparisons : 7998000    Number of copying objects : 4000
//5000Values in array - Number of comparisons : 12497500   Number of copying objects : 5000
//6000Values in array - Number of comparisons : 17997000   Number of copying objects : 6000
//7000Values in array - Number of comparisons : 24496500   Number of copying objects : 7000
//8000Values in array - Number of comparisons : 31996000   Number of copying objects : 8000
//9000Values in array - Number of comparisons : 40495500   Number of copying objects : 9000
//10000Values in array - Number of comparisons : 49995000  Number of copying objects : 10000
//25000Values in array - Number of comparisons : 312487500 Number of copying objects : 25000
//50000Values in array - Number of comparisons : 1249975000        Number of copying objects : 50000
//100000Values in array - Number of comparisons : 4999950000       Number of copying objects : 100000
//
//test_sorted_array - Quick :
//	1000Values in array - Number of comparisons : 1488       Number of copying objects : 1488
//	2000Values in array - Number of comparisons : 2976       Number of copying objects : 2976
//	3000Values in array - Number of comparisons : 4094       Number of copying objects : 4094
//	4000Values in array - Number of comparisons : 5952       Number of copying objects : 5952
//	5000Values in array - Number of comparisons : 7952       Number of copying objects : 7952
//	6000Values in array - Number of comparisons : 8190       Number of copying objects : 8190
//	7000Values in array - Number of comparisons : 9904       Number of copying objects : 9904
//	8000Values in array - Number of comparisons : 11904      Number of copying objects : 11904
//	9000Values in array - Number of comparisons : 13904      Number of copying objects : 13904
//	10000Values in array - Number of comparisons : 15904     Number of copying objects : 15904
//	25000Values in array - Number of comparisons : 33616     Number of copying objects : 33616
//	50000Values in array - Number of comparisons : 67232     Number of copying objects : 67232
//	100000Values in array - Number of comparisons : 134464   Number of copying objects : 134464

//===REVERSE SORTED=====

//1000Values in array - Number of comparisons : 499500     Number of copying objects : 1000
//2000Values in array - Number of comparisons : 1999000    Number of copying objects : 2000
//3000Values in array - Number of comparisons : 4498500    Number of copying objects : 3000
//4000Values in array - Number of comparisons : 7998000    Number of copying objects : 4000
//5000Values in array - Number of comparisons : 12497500   Number of copying objects : 5000
//6000Values in array - Number of comparisons : 17997000   Number of copying objects : 6000
//7000Values in array - Number of comparisons : 24496500   Number of copying objects : 7000
//8000Values in array - Number of comparisons : 31996000   Number of copying objects : 8000
//9000Values in array - Number of comparisons : 40495500   Number of copying objects : 9000
//10000Values in array - Number of comparisons : 49995000  Number of copying objects : 10000
//25000Values in array - Number of comparisons : 312487500 Number of copying objects : 25000
//50000Values in array - Number of comparisons : 1249975000        Number of copying objects : 50000
//100000Values in array - Number of comparisons : 4999950000       Number of copying objects : 100000
//
//test_reverse_sorted_array - Quick :
//	1000Values in array - Number of comparisons : 2488       Number of copying objects : 1989
//	2000Values in array - Number of comparisons : 4976       Number of copying objects : 3977
//	3000Values in array - Number of comparisons : 7092       Number of copying objects : 5593
//	4000Values in array - Number of comparisons : 9952       Number of copying objects : 7953
//	5000Values in array - Number of comparisons : 12952      Number of copying objects : 10453
//	6000Values in array - Number of comparisons : 14188      Number of copying objects : 11189
//	7000Values in array - Number of comparisons : 16904      Number of copying objects : 13405
//	8000Values in array - Number of comparisons : 19904      Number of copying objects : 15905
//	9000Values in array - Number of comparisons : 22904      Number of copying objects : 18405
//	10000Values in array - Number of comparisons : 25904     Number of copying objects : 20905
//	25000Values in array - Number of comparisons : 58616     Number of copying objects : 46117
//	50000Values in array - Number of comparisons : 117232    Number of copying objects : 92233
//	100000Values in array - Number of comparisons : 234464   Number of copying objects : 184465


// =====SPEED TEST======
//Quick sort :
//1000 - Values in array.Time Quick sort - 0.000182711
//2000 - Values in array.Time Quick sort - 0.000408604
//3000 - Values in array.Time Quick sort - 0.000620569
//4000 - Values in array.Time Quick sort - 0.000862203
//5000 - Values in array.Time Quick sort - 0.00108466
//6000 - Values in array.Time Quick sort - 0.00136296
//7000 - Values in array.Time Quick sort - 0.00159221
//8000 - Values in array.Time Quick sort - 0.00185935
//9000 - Values in array.Time Quick sort - 0.00209707
//10000 - Values in array.Time Quick sort - 0.00239375
//25000 - Values in array.Time Quick sort - 0.00645463
//50000 - Values in array.Time Quick sort - 0.0137295
//100000 - Values in array.Time Quick sort - 0.0289815
//
//
//Selection sort :
//1000 - Values in array.Time Selection sort - 0.00634512
//2000 - Values in array.Time Selection sort - 0.0252298
//3000 - Values in array.Time Selection sort - 0.0566937
//4000 - Values in array.Time Selection sort - 0.100765
//5000 - Values in array.Time Selection sort - 0.157499
//6000 - Values in array.Time Selection sort - 0.22693
//7000 - Values in array.Time Selection sort - 0.308624
//8000 - Values in array.Time Selection sort - 0.403351
//9000 - Values in array.Time Selection sort - 0.509278
//10000 - Values in array.Time Selection sort - 0.628828
//25000 - Values in array.Time Selection sort - 3.91936
//50000 - Values in array.Time Selection sort - 15.6386
//100000 - Values in array.Time Selection sort - 62.4666
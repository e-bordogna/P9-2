/*
 *
 * File: P9-2.sln
 * Author: Enzo M Bordogna
 * Date: 10/26/2023
 *
 */

#include <iostream>
#include <string>
using namespace std;

bool isSortedIncreasing(const int* a, int size);
bool isSortedDecreasing(const int* a, int size);
bool hasAdjacentDuplicates(const int* a, int size);
bool hasDuplicates(const int* a, int size);

int main() {
	int array[6];
	int size = 1;
	int input;
	while (size < 7) {
		cout << "Enter integer #" << size << ": ";
		cin >> input;
		array[size - 1] = input;
		size++;
	}

	isSortedIncreasing(array, size);
	isSortedDecreasing(array, size);
	hasAdjacentDuplicates(array, size);
	hasDuplicates(array, size);
	cout << "Press any key to continue . . .";
	return 0;
}

//size = 6
bool isSortedIncreasing(const int* a, int size) {
	const int* p = a;
	for (int i = 0; i < size - 1; i++) {
		if (*(p + 1) < *p) {
			cout << "The data are not increasing." << endl;
			return false;
		}
	}
	cout << "The data are increasing." << endl;
	return true;
}
bool isSortedDecreasing(const int* a, int size) {
	const int* p = a;
	for (int i = 0; i < size - 1; i++) {
		if (*(p + 1) > *p) {
			cout << "The data are not decreasing." << endl;
			return false;
		}
		p++;
	}
	cout << "The data are decreasing." << endl;
	return true;
}
bool hasAdjacentDuplicates(const int* a, int size) {
	const int* p = a;
	for (int i = 0; i < size; i++) {
		if (*(p + 1) == *p) {
			cout << "The data has adjacent duplicates." << endl;
			return true;
		}
		p++;
	}
	cout << "The data has no adjacent duplicates." << endl;
	return false;
}
bool hasDuplicates(const int* a, int size) {
	const int* p = a;
	const int* q = &a[1];
	for (int i = 0; i < size - 1; i++) {
		p = &a[i];
		for (int j = i + 1; j < size; j++) {
			q = &a[j];
			if (*q == *p) {
				cout << "The data has duplicates." << endl;
				return true;
			}
		}
	}
	cout << "The data has no duplicates." << endl;
	return false;
}
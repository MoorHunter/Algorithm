//#include <iostream>
//#include <algorithm>
//#include "SortTestHelper.h"
//#include "Sort.h"
//
//using namespace std;
//
//
//
//int main() {
//
//	int n = 10000;
//	cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;
//	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
//	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
//	
//	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
//	SortTestHelper::testSort("heap Sort", heapSort1, arr2, n);
//
//
//	
//	cout << "Test for generateNearlyOrderedArray, sizequickSort = " << n << ", random range [0, " << n << "]" << endl;
//	int *arr3 = SortTestHelper::generateNearlyOrderedArray(n, 10);
//	int *arr4 = SortTestHelper::copyIntArray(arr3, n);
//	SortTestHelper::testSort("Insertion Sort", insertionSort, arr3, n);
//	SortTestHelper::testSort("heap Sort", heapSort1, arr4, n);
//	//SortTestHelper::testSort("Bobble Sort", bubbleSort, arr3, n);
//	//SortTestHelper::testSort("Shell Sort", mergeSort, arr2, n);
//	delete[] arr1;
//	
//	delete[] arr2;
//	delete[] arr3;
//	delete[] arr4;
//	cout << endl;
//	system("pause");
//	return 0;
//}
#pragma once
#ifndef INC_04_INSERTION_SORT_SELECTIONSORT_H
#define INC_04_INSERTION_SORT_SELECTIONSORT_H

#include <iostream>
#include <algorithm>
#include<vector>
#include"MaxHeap.h"
using namespace std;


template<typename T>
void selectionSort(T arr[], int n) {  //1                                                    //O(n^2)

	for (int i = 0; i < n; i++) {

		int minIndex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		swap(arr[i], arr[minIndex]);
	}
}


template<typename T>
void insertionSort(T arr[], int n) {    //2                                                    //O(n^2)

	for (int i = 1; i < n; i++) {

		//// 寻找元素arr[i]合适的插入位置
		//// 写法1
		////        for( int j = i ; j > 0 ; j-- )
		////            if( arr[j] < arr[j-1] )
		////                swap( arr[j] , arr[j-1] );
		////            else
		////                break;
		//// 写法2
		//for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
		//	swap(arr[j], arr[j - 1]);
		T e = arr[i];
		int j;
		for (j = i; j > 0 && e < arr[j - 1]; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}

	return;
}
template<typename T>
void insertionSort(T arr[], int l, int r) {//2*
	for (int i = l + 1; i <= r; i++) {
		T e = arr[i];
		int j;
		for (j = i; j > l&&arr[j - 1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
	return;
}

template<typename T>
void bubbleSort(T arr[], int n) {//3
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
			if (arr[j]>arr[j + 1])
				swap(arr[j], arr[j + 1]);

	return;
}
//希尔排序
template<typename T>
void shellSort(T arr[], int n) {//4
	int gap = n / 2;
	int j = 0, x = 0;
	while (gap > 0) {
		for (int i = gap + 1; i < n; i++) {
			if (arr[i] < arr[i - gap]) {
				x = arr[i];
				j = i - gap;
				while (x < arr[j] && j >= 0) {
					arr[j + gap] = arr[j];
					j = j - gap;
				}
				arr[j + gap] = x;
			}
		}
		gap = gap / 2;
	}
	return;
}
//归并排序
template<typename T>
void __merge(T arr[], int l, int mid, int r) {

	//T A[r - l + 1];
	//vector<T> A[r - l + 1];
	T* A=new T[r - l + 1];
	for (int i = l; i <= r; i++)
		A[i - l] = arr[i];

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = A[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = A[i - l];
			i++;
		}
		else if (A[i - l] < A[j - l]) {
			arr[k] = A[i - l];
			i++;
		}
		else {
			arr[k] = A[j - l];
			j++;
		}
	}
	delete[]A;
}
//递归使用归并排序，对arr[l。。。。r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {
	if (l >= r)return;
	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if (arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}
template<typename T>
void mergeSort(T arr[], int n) {//5
	__mergeSort(arr, 0, n - 1);
}

template<typename T>
void mergeSortBU(T arr[], int n) {//5*
	for (int sz = 1; sz <= n; sz += sz) {
		for (int i = 0; i + sz < n; i += sz + sz) {
			if (arr[i + sz - 1] > arr[i + sz])
				__merge(arr, i, i + sz - 1, min(i + sz + sz, n - 1));
		}
	}
	return;
}
template<typename T>
int __patition(T arr, int l, int r) {
	//


	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int j = l;
	//arr[l+1.....j]<v;arr[j+1........i)>v
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < *v) {
			swap(arr[++j], arr[i]);
			//j++;
		}
	}
	swap(arr[j], arr[l]);
	return j;
}
template<typename T>
void __quickSort(T arr[], int l, int r) {
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	int p = __patition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}
template<typename T>
void quickSort(T arr[], int n) {//6
	srand(time(NULL));
	__quickSort(arr, 0, n - 1);
}

template<typename T>
int __partition2(T arr[], int l, int r) {
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int i = l + 1, j = r;
	while (ture) {
		while (i <= r&&arr[i] < v)i++;
		while (j >= l + 1 && arr[j]>v)j--;
		if (i > j)break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}

template<typename T>
void __quickSort2(T arr[], int l, int r) {
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	int p = __patition2(arr, l, r);
	__quickSort2(arr, l, p - 1);
	__quickSort2(arr, p + 1, r);
}
template<typename T>
void quickSort2(T arr[], int n) {//6*
	srand(time(NULL));
	__quickSort2(arr, 0, n - 1);
}
template<typename T>
void __quickSort3(T arr[], int l, int r) {
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	//partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int lt = l;//arr[l+1....lt]<v
	int gt = r + 1;//arr[gt.....r]>v
	int i = l + 1;//arr[lt+1.....i)=v
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i]>v) {
			swap(arr[i], arr[gt - 1]);
			gt--;

		}
		else {
			i++
		}
	}
	swap(arr[l], arr[gt]);
}
template<typename T>
void quickSort3(T arr[], int n) {//6**
	srand(time(NULL));
	__quickSort3(arr, 0, n - 1);
}

template<typename T>
void heapSort1(T arr, int n) {//7
	MaxHeap<T>maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
		maxheap.insert(arr[i]);

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extraMax();
}
template<typename T>
void heapSort2(T arr[], int n) {//7*
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extraMax();
}
template<typename T>
void __shiftDown(T arr[], int n, int k) {
	while (2 * k+1 <= n) {
		int j = 2 * k+1;//此轮循环中data[k]与data[j]交换位置
		if (j + 1 <= n&&arr[j + 1]>arr[j])
			j += 1;
		if (arr[k] >= arr[j])
			break;
		swap(arr[k], arr[j]);
		k = j;
	}
}
template<typename T>
void heapSort(T arr[], int n) {//8
	//heapify
	for (int i = (n - 1) / 2; i >= 0; i--)
		__shiftDown(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}
#endif //INC_04_INSERTION_SORT_SELECTIONSORT_H

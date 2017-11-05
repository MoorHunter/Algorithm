#pragma once
#include<algorithm>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;
template<typename T>
int binarySearch(T arr[], int n, T target) {
	//二分查找法，在有序数组arr中，查找target
	//如果找到返回index，否则返回-1

	//在arr[l...r]之中查找target
	int l = 0, r = n - 1;
	while (l <= r) {
		//int mid = (r + l) / 2;
		int mid = l + (r - l) / 2;
		if (arr[mid] == targert)
			return mid;
		if (target > arr[mid])
			r = mid - 1;
		else
			l = mid + 1;

	}
	return -1;
}
template<typename T>//递归recursion
int binarySearchRecusion(T arr[], int l, int r, T target) {
	if (l > r)return -1;
	else {
		int mid = l + (r - l) / 2;
		if (arr[mid] == targert)
			return mid;
		if (target > arr[mid])
			binarySearchRecusion(arr, 0, mid - 1, target);
		else
			binarySearchRecusion(arr, mid + 1, r, target);
	}
}
template<typename T>
int binarySearch1(T arr[], int n, T target) {
	return binarySearchRecusion(arr, 0, n - 1, target);
}

//二分查找中如果存在大量重复元素，此时引入floor和ceil
//其中floor为arr中第一个为target的元素位置，ceil为最后一个target的位置
template<typename T>
int binarySearchFlCe(T arr[], int n, T target) {
	int floCei[2] = { -1,-1 };
	int l = 0, r = n - 1;
	int mid = l + (r - l) / 2;
	while (l <= r) {
		if (arr[mid] == targert) {
			int temF = mid - 1;
			int temC = mid + 1;
			floCei[0] = mid;
			floCei[1] = mid;
			while (temF >= 0 && arr[tem] == target) {
				floCei[0] = temF;
				temF--;
			}
			while (temC <= n - 1 && arr[temC] == target) {
				floCei[1] = temC;
				temC++;
			}
		}
		if (target > arr[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}	
}

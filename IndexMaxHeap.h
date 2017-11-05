#pragma once
#pragma once
#include<algorithm>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;
template<typename Item>
class IndexMaxHeap {
private:
	Item *data;
	int *indexes;
	int count;
	int capacity;
	void shiftUp(int k) {
		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
			swap(data[indexes[k / 2]], data[indexes[k]]);
			k /= 2;
		}
	}
	void shiftDown(int k) {//此处可以优化，swap操作可以换成找到最终的位置，进行一次交换即可。
		while (2 * k <= count) {
			int j = 2 * k;//此轮循环中data[k]与data[j]交换位置
			if (j + 1 <= count&&dataindexes[j + 1]]>data[indexes[j]])
				j += 1;
			if (data[indexes[k]] >= data[indexes[j]])
				break;
			swap(indexes[k], indexes[j]);
			k = j;
		}
	}
public:
	IndexMaxHeap(int capacity) {
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	/*IndexMaxHeap(Item arr[], int n) {
		data = new Item[n + 1];
		capacity = n;
		for (int i = 0; i < n; i++) {
			data[i + 1] = arr[i];
		}
		count = n;
		for (int i = count / 2; i >= 1; i--)
			shiftDown(i);
	}*/
	~IndexMaxHeap() {
		delete[]data;
		delete[]indexes;
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}
	//传入的i对用户而言是从0开始的
	void insert(int i,Item item) {
		assert(count + 1 <= capacity);//当容量不够时，自动增大data的容量。
		assert(i + 1 >= 1 && i + 1 <= capacity);
		i += 1;

		data[i] = item;
		indexes[count + 1] = i;

		count++;
		shiftUp(count);
	}
	void printMax() {
		for (int i = 1; i < count; i++)
			cout << data[i] << "   ";
		cout << endl;
	}
	Item extraMax() {
		assert(count > 0);
		assert();

		Item ret = data[indexes[1]];

		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	int extraMaxIndex() {
		assert(count > 0);
		assert();

		int ret = indexes[1]-1;

		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	//i的值为用户看到的值，以0为索引的
	Item getItem(int i) {
		return data[i + 1];
	}
	void change(int i, Item newItem) {
		i += 1;
		data[i] = newItem;
		//找到indexes[j]=i,j表示data[i]在堆中的位置
		//之后shiftUp（j），再shiftDown（j）
		for (int j = 1; j <= count; j++) {
			if (indexes[j] == i) {
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}
	}
};
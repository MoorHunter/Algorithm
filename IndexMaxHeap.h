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
	void shiftDown(int k) {//�˴������Ż���swap�������Ի����ҵ����յ�λ�ã�����һ�ν������ɡ�
		while (2 * k <= count) {
			int j = 2 * k;//����ѭ����data[k]��data[j]����λ��
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
	//�����i���û������Ǵ�0��ʼ��
	void insert(int i,Item item) {
		assert(count + 1 <= capacity);//����������ʱ���Զ�����data��������
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
	//i��ֵΪ�û�������ֵ����0Ϊ������
	Item getItem(int i) {
		return data[i + 1];
	}
	void change(int i, Item newItem) {
		i += 1;
		data[i] = newItem;
		//�ҵ�indexes[j]=i,j��ʾdata[i]�ڶ��е�λ��
		//֮��shiftUp��j������shiftDown��j��
		for (int j = 1; j <= count; j++) {
			if (indexes[j] == i) {
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}
	}
};
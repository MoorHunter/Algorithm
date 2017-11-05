//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<cmath>
//#include<cassert>
//#include <ctime>
//#include"MaxHeap.h"
//using namespace std;
//
//int main() {
//	MaxHeap<int>maxheap = MaxHeap<int>(1000);
//	
//
//	srand(time(NULL));
//	for (int i = 0; i < 1000; i++){
//		int a = rand() % 1000;
//		maxheap.insert(a);
//	}
//	maxheap.printMax();
//	cout << maxheap.size() << endl;
//	/*clock_t startTime = clock();
//	sort(arr, n);
//	clock_t endTime = clock();
//	cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;*/
//	clock_t startTime = clock();
//	while (!maxheap.isEmpty())
//		cout << maxheap.extraMax() << "  ";
//	clock_t endTime = clock();
//	cout << endl;
//	cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
//	system("pause");
//	return 0;
//}
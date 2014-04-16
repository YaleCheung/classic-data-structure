#include <stdlib.h>
#include <iostream>
#include "MaxHeap.h"
#include <ctime>
int main(){
	time_t seed = time(NULL);
	srand(seed);
	CMaxHeap<int> maxheap(100);
	printf("insert>...\n");
	int array[20];
	for(int i = 0; i < 15; i++){
		int val = rand() % 20;
		maxheap.mInsert(val);
		array[i] = val;
	}
	maxheap.mPrint();
    printf("initialize>...\n");
	maxheap.mInitialize(array,15,100);
	maxheap.mPrint();
    printf("delmax>...\n");
	int tmp;
	maxheap.mDeleteMax(tmp);
	printf("tmp:>  %d\n",tmp);
	maxheap.mPrint();
	system("pause");
	return 0;
}
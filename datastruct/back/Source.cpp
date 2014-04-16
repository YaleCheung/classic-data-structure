#include <stdlib.h>
#include <iostream>
#include "CLinkQueue.h"
using namespace std;
int main(){
    
	CLinkQueue<int> queue;
	for(auto i = 0; i < 5; i ++){
		queue.mAdd(i);
		cout << queue.mFirst() << '\t';
		cout << queue.mLast() << endl;
	}
	for(auto i = 0; i < 5; i ++)
		queue.mDelete();
	system("pause");
	return 0;
}
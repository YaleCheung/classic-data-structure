#include "CSparseMatrix.h"
#include <iostream>
using namespace std;
int main(){
	CSparseMatrix<int> matrix(5);
	cin >> matrix;
	cout << matrix;
	CSparseMatrix<int> tmp(20);
	matrix.mAdd(matrix,tmp);
	cout << tmp;
	CSparseMatrix<int> tmp2(20);
	matrix.mTranpose(tmp2);
	cout << tmp2;
	system("pause");
	return 0;
}
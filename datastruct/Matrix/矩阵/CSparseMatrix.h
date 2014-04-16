#ifndef CSPARSEMATRIX_HHH
#define CAPARSEMATRIX_HHH

#include <iostream>
#include <cassert>
template<typename T>
class CSparseMatrix;

template<typename T>
struct SDataType{
    friend class CSparseMatrix<T>;
    int m_nRow;
	int m_nCol;
	T m_nVal;
};

template <typename T>
class CSparseMatrix{
private:
	// members;
	SDataType<T>* m_pArray;
	int m_nLength;
	int m_nMaxSize;
	int m_nRows;
	int m_nCols;

public:
	// constructors;
	CSparseMatrix(const int& maxSize);
	~CSparseMatrix();
	// methods;
	friend std::ostream& operator<< (std::ostream& out, const CSparseMatrix<T>& matrix){
		out << "rows = " << matrix.m_nRows << " columns = " << matrix.m_nCols << std::endl;
		out << "length = " << matrix.m_nLength << std::endl;
		out << "row" << '\t' << "col" << '\t' <<  "val" << std::endl;
		for(int i = 0; i < matrix.m_nLength; i ++)
			out << matrix.m_pArray[i].m_nRow << '\t' << matrix.m_pArray[i].m_nCol << '\t' << matrix.m_pArray[i].m_nVal << std::endl;
		return out;
	}
	friend std::istream& operator>> (std::istream& in, CSparseMatrix<T>& matrix){
		std::cout << "number of rows, columns, length" << std::endl;
		in >> matrix.m_nRows >> matrix.m_nCols >> matrix.m_nLength;
		assert(matrix.m_nLength <= matrix.m_nMaxSize);
		for(int i = 0; i < matrix.m_nLength; i ++){
			std::cout << "row number, column number, value" << std::endl;
			in >> matrix.m_pArray[i].m_nRow >> matrix.m_pArray[i].m_nCol >> matrix.m_pArray[i].m_nVal;
		}
		return in;
	}
    // append;
	void mAdd(const CSparseMatrix<T>& aMatrix, CSparseMatrix<T>& bMatrix);
	void mTranpose(CSparseMatrix<T>& aMatrix);
private:
    void mAppend(const SDataType<T>& data);
};

template<typename T>
CSparseMatrix<T>::CSparseMatrix(const int& maxSize = 10):
    m_nMaxSize(maxSize){
    assert(m_nMaxSize > 0);
	m_nLength = m_nCols = m_nRows = 0;
	m_pArray = new SDataType<T>[m_nMaxSize];
}

template<typename T>
CSparseMatrix<T>::~CSparseMatrix(){
	delete [] m_pArray;
}

template<typename T>
void CSparseMatrix<T>::mAppend(const SDataType<T>& data){
	if(m_nLength >= m_nMaxSize)
		printf("the matrix is full, cannot append any more\n");
	else{
        m_pArray[m_nLength] = data;
		m_nLength ++;
	}
}	

template<typename T>
void CSparseMatrix<T>::mAdd(const CSparseMatrix<T>& aMatrix, CSparseMatrix<T>& bMatrix){
    if(aMatrix.m_nRows != m_nRows || aMatrix.m_nCols != m_nCols)
		printf("the matrix is not compatable\n");

	bMatrix.m_nCols = m_nCols;
	bMatrix.m_nRows = m_nRows;
	bMatrix.m_nLength = 0;
    
	int i = 0;    // indicator of self;
	int j = 0;    // indicator of aMatrix;
    while(i < m_nLength && j < aMatrix.m_nLength){
		if(bMatrix.m_nLength == bMatrix.m_nMaxSize){
			printf("Not enough size to add");
			return;
		}

		int ipos = m_pArray[i].m_nRow * m_pArray[i].m_nCol + m_pArray[i].m_nCol;
		int jpos = aMatrix.m_pArray[j].m_nRow * aMatrix.m_pArray[j].m_nCol  + aMatrix.m_pArray[j].m_nCol;
        if(ipos < jpos){
			bMatrix.mAppend(m_pArray[i]);
			i ++;
		}else if(ipos > jpos){
			bMatrix.mAppend(aMatrix.m_pArray[j]);
			j ++;
		}else{
			SDataType<T> data;
			data.m_nVal = m_pArray[i].m_nVal + aMatrix.m_pArray[j].m_nVal;
			data.m_nRow = m_pArray[i].m_nRow;
			data.m_nCol = m_pArray[i].m_nCol;
			bMatrix.mAppend(data);
			i ++;
			j ++;
		}
		bMatrix.m_nLength ++;
	}
	while(i < m_nLength){
		if(bMatrix.m_nLength == bMatrix.m_nMaxSize){
			printf("Not enough size to add");
			return;
		}

		bMatrix.mAppend(m_pArray[i]);
		i ++;
	}
	while(j < bMatrix.m_nLength){
		if(bMatrix.m_nLength == bMatrix.m_nMaxSize){
			printf("Not enough size to add");
			return;
		}
	    bMatrix.m_pArray[j];
		j ++;
	}
}

template<typename T>
void CSparseMatrix<T>::mTranpose(CSparseMatrix<T>& matrix){
	if(m_nLength > matrix.m_nMaxSize){
		printf("Not enough mem\n");
		return;
	}
    matrix.m_nCols = m_nRows;
	matrix.m_nRows = m_nCols;
    matrix.m_nLength = m_nLength;

    int* numberInCol = new int[m_nCols + 1];
	int* nextOrderByRow = new int[m_nRows + 1];

	// initialize
	for(int i = 0; i < m_nCols; i ++)
		numberInCol[i] = 0;

	nextOrderByRow[1] = 0;
	nextOrderByRow[0] = 0;

	for(int i = 1; i <= m_nLength; i ++)
		numberInCol[m_pArray[i].m_nCol] ++;
	for(int j = 2; j <= m_nCols; j ++) // row start;
		nextOrderByRow[j] = nextOrderByRow[j - 1] + numberInCol[j - 1];
    
    for(int i = 0; i < m_nLength; i ++){
		int pos = nextOrderByRow[m_pArray[i].m_nCol] ++;
		matrix.m_pArray[pos].m_nRow = m_pArray[i].m_nCol;
		matrix.m_pArray[pos].m_nCol = m_pArray[i].m_nRow;
		matrix.m_pArray[pos].m_nVal = m_pArray[i].m_nVal;
	}
}
#endif
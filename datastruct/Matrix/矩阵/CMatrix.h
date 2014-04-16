#ifndef CMATRIX_HHH
#define CMATRIX_HHH

#include <cassert>
#include <iostream>
#include <stdlib.h>
template<typename T>
class CMatrix{
private:
	// members;
    T* m_pElem;
	int m_nRow, m_nCol;   //the number of rows: m_nRow. So as to m_nCol;
public:
	// constructors;
    CMatrix(const int& row, const int& m_nCol);
	CMatrix(const CMatrix<T>& matrix);
	~CMatrix();
	// methods;
	// print the matrix out;
	void print(std::ostream& out);
    // operator+;
	CMatrix<T> operator+() const;
	CMatrix<T> operator+(const CMatrix<T>& matrix) const;
	// operator-;
	CMatrix<T> operator-() const;
	CMatrix<T> operator-(const CMatrix<T>& matrix) const;
	// operator*;
	CMatrix<T> operator*(const T& data) const;
	CMatrix<T> operator*(const CMatrix<T>& matrix) const;
	// operator ();
	T& operator()(const int& i, const int& j) const;
	// operator =;
	CMatrix<T>& operator=(const CMatrix<T>& matrix);
	// operator +=;
	CMatrix<T>& operator+=(const CMatrix<T>& matrix);
	// print;
	// row num;
	int mRows() const;
	// col num;
	int mCols() const;
};
// operator <<
	//friend std::ostream& operator<<(std::ostream& out, const CMatrix<T>& matrix);
	// row num;
template<typename T>
void CMatrix<T>::print(std::ostream& out){
    for(int i = 0; i < m_nRow * m_nCol; i ++){
		if( i % m_nCol == 0 )
			out << endl;
		out << m_pElem[i] << " ";
	}
	out <<endl;
}

template <typename T>
CMatrix<T>::CMatrix(const int& row, const int& col):
    m_nRow(row), m_nCol(col){
	assert((m_nRow > 0) && (m_nCol > 0));
    int length = row * col;
    m_pElem = new T[length];
}

template <typename T>
CMatrix<T>::CMatrix(const CMatrix<T>& matrix):
    m_nRow(matrix.m_nRow), m_nCol(matrix.m_nCol){
	assert((m_nRow > 0) && (m_nCol > 0));
	m_pElem = new T[m_nRow * m_nCol];
	for(int i = 0; i < m_nRow * m_nCol; i ++)
		m_pElem[i] = matrix.m_pElem[i];
}

template <typename T>
CMatrix<T>::~CMatrix(){
	delete [] m_pElem;
}

template <typename T>
T& CMatrix<T>::operator()(const int& i, const int& j) const{
    assert((i > 0 && i <= m_nRow) && (j > 0 && j <= m_nCol));
    return m_pElem[(i - 1) * m_nCol + j - 1];
}

template <typename T>
CMatrix<T> CMatrix<T>::operator+() const{
	CMatrix<T> tmpMatrix(m_nRow, m_nCol);
	for(int i = 0; i < m_nRow * m_nCol; i ++){
        tmpMatrix.m_pElem[i] = abs(m_pElem[i]);
	}
	return tmpMatrix;
}

template <typename T>
CMatrix<T> CMatrix<T>::operator+(const CMatrix<T>& matrix) const{
    assert((m_nRow == matrix.m_nRow) && (m_nCol == matrix.m_nCol));
	CMatrix<T> tmpMatrix(m_nRow, m_nCol);
    for(int i = 0; i < m_nRow * m_nCol; i ++){
        tmpMatrix.m_pElem[i] = m_pElem[i] + matrix.m_pElem[i];
	}
	return tmpMatrix;
}

template <typename T>
CMatrix<T> CMatrix<T>::operator-() const{
	CMatrix<T> tmpMatrix(m_nRow, m_nCol);
	for(int i = 0; i < m_nRow * m_nCol; i ++){
        tmpMatrix.m_pElem[i] = (-m_pElem[i]);
	}
	return tmpMatrix;
}

template <typename T>
CMatrix<T> CMatrix<T>::operator-(const CMatrix<T>& matrix) const{
    assert((m_nRow == matrix.m_nRow) && (m_nCol == matrix.m_nCol));
	CMatrix<T> tmpMatrix(m_nRow, m_nCol);
    for(int i = 0; i < m_nRow * m_nCol; i ++){
        tmpMatrix.m_pElem[i] = m_pElem[i] - matrix.m_pElem[i];
	}
	return tmpMatrix;
}
template<typename T>
CMatrix<T> CMatrix<T>::operator*(const T& data) const{
	CMatrix<T> tmpMatrix(m_nRow, m_nCol);
	for(int i = 0; i < m_nRow * m_nCol; i ++)
		tmpMatrix.m_pElem[i] = m_pElem[i]  * data;
	return tmpMatrix;
}
template <typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& matrix) const{
    assert(matrix.m_nRow == m_nCol);
	CMatrix<T> tmpMatrix(m_nRow, matrix.m_nCol);
    
	for(int i = 0; i < m_nRow; i ++){
       for(int j = 0; j < matrix.m_nCol; j ++){
		   tmpMatrix.m_pElem[i * matrix.m_nCol + j] = 0;
		   for(int k = 0; k < matrix.m_nRow; k ++){
			   tmpMatrix.m_pElem[i * matrix.m_nCol + j] += m_pElem[i * m_nCol + k] * matrix.m_pElem[j + matrix.m_nCol * k];
		   }
	    }
	}
	return tmpMatrix;
        
}

template <typename T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& matrix){
	m_nRow = matrix.m_nRow;
	m_nCol = matrix.m_nCol;
	delete [] m_pElem;
	m_pElem = new T[m_nRow * m_nCol];
	for(int i = 0; i < m_nRow * m_nCol; i ++){
		m_pElem[i] = matrix.m_pElem[i];
	}
	return *this;
}

template <typename T>
CMatrix<T>& CMatrix<T>::operator+=(const CMatrix<T>& matrix){
    assert((m_nRow == matrix.m_nRow) && (m_nCol == matrix.m_nCol));
    for(int i = 0; i < m_nRow * m_nCol; i ++)
		m_pElem[i] += matrix.m_pElem[i];
	return *this;
}

template <typename T>
int CMatrix<T>::mRows() const{
	return m_nRow;
}

template <typename T>
int CMatrix<T>::mCols() const{
	return m_nCol;
}
#endif
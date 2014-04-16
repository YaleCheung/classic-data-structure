#ifndef CARRAY2D_HHH
#define CARRAY2D_HHH

#include <cassert>
#include "Array1D.h"

template<typename T>
class CArray2D{
private:
	// members;
	int m_nRow, m_nCol;
	CArray1D<T>* m_pArray;
public:
    // constructors;
	CArray2D(const int& row, const int& col);
	CArray2D(const CArray2D& array);
    ~CArray2D();

    // methods;	
	// row Size;
	int mRowSize() const;
	// col Size;
	int mColSize() const;
	// operator [];
	CArray1D<T>& operator[](int index) const;
	// operator +;
	CArray2D<T> operator+() const;
	CArray2D<T> operator+(const CArray2D<T>& array) const;
	// operator -;
	CArray2D<T> operator-() const;
	CArray2D<T> operator-(const CArray2D<T>& array) const;
    // operator *;
	CArray2D<T> operator*(const CArray2D<T>& array) const;
	// operator =;
	CArray2D<T>& operator=(const CArray2D<T>& array);
	// operator +=;
	CArray2D<T>& operator+=(const CArray2D<T>& array);
	// print;
	void print(std::ostream& out) const;
};

template<typename T>
CArray2D<T>::CArray2D(const int& row, const int& col):
    m_nRow(row), m_nCol(col){
	assert((row > 0) && (col > 0));
	m_pArray = new CArray1D<T>[row];
	for(int i = 0; i < row; i ++)
		m_pArray[i].mResize(m_nCol);
}

template<typename T>
CArray2D<T>::CArray2D(const CArray2D<T>& array):
    m_nRow(array.m_nRow), m_nCol(array.m_nCol){
		m_pArray = new CArray1D<T>[m_nRow];
		for(int i = 0; i < m_nRow; i ++){
			m_pArray[i] = array[i];
		}
}

template<typename T>
CArray2D<T>::~CArray2D(){
	delete [] m_pArray;
}

template<typename T>
int CArray2D<T>::mColSize() const{
	return m_nCol;
}

template<typename T>
int CArray2D<T>::mRowSize() const{
	return m_nRow;
}

template<typename T>
CArray1D<T>& CArray2D<T>::operator[](int index) const{
	assert((m_nCol > 0) && (m_nRow > 0));
	return m_pArray[index];
}

template<typename T>
CArray2D<T>& CArray2D<T>::operator=(const CArray2D<T>& array){
	if(&array != this){
        delete [] m_pArray;
	    m_pArray = new CArray1D<T>[m_nRow];	
		m_nRow = array.m_nRow;
		m_nCol = array.m_nCol;

		for(int i = 0; i < m_nRow; i ++){
			m_pArray[i] = array[i];
		}
	}
	return *this;
}

template<typename T>
CArray2D<T> CArray2D<T>::operator+() const{
	CArray2D<T> tmp(m_nRow, m_nCol);
	for(int i = 0; i < m_nRow; i ++)
       tmp.m_pArray[i] = (+m_pArray[i]);
	return tmp;
}

template<typename T>
CArray2D<T> CArray2D<T>::operator+(const CArray2D<T>& array) const{
	assert((m_nRow == array.m_nRow) && (m_nCol == array.m_nCol));
	CArray2D<T> tmp(m_nRow, m_nCol);
	for(int i = 0; i < m_nRow; i ++)
		tmp.m_pArray[i] = this->m_pArray[i] + array.m_pArray[i];
    return tmp;
}

template<typename T>
CArray2D<T> CArray2D<T>::operator-() const{
	CArray2D<T> tmp(m_nRow, m_nCol);
	for(int i = 0; i < m_nRow; i ++)
       tmp.m_pArray[i] = (-m_pArray[i]);
	return tmp;
}


template<typename T>
CArray2D<T> CArray2D<T>::operator-(const CArray2D<T>& array) const{
	assert((m_nRow == array.m_nRow) && (m_nCol == array.m_nCol));
	CArray2D<T> tmp(m_nRow, m_nCol);
	for(int i = 0; i < m_nRow; i ++)
		tmp.m_pArray[i] = this->m_pArray[i] - array.m_pArray[i];
    return tmp;
}

template<typename T>
CArray2D<T> CArray2D<T>::operator*(const CArray2D<T>& array) const{
	assert(array.m_nCol == m_nRow);
	CArray2D<T> tmp(m_nRow, array.m_nCol);
	for(int i = 0; i < m_nRow; i ++){
		for(int j = 0; j < array.m_nCol; j ++){
			tmp.m_pArray[i][j] = 0;
			for(int k = 0; k < m_nCol; k ++)
				tmp.m_pArray[i][j] += m_pArray[i][k] * array.m_pArray[k][j];
		}
	}
    return tmp;
}

template<typename T>
void CArray2D<T>::print(std::ostream& out) const{
	for(int i = 0; i < m_nRow; i ++)
		m_pArray[i].print(out);
}
#endif
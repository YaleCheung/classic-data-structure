#ifndef ARRAY1D_HHH
#define ARRAY1D_HHH
#include <stdlib.h>
#include <iostream>
#include <cassert>

template<typename T>
class CArray1D{
private:
	// members;
	int m_nSize;
	T* m_pElem;
public:
	// methods;
	// constructors;
	CArray1D():
		m_nSize(10) { m_pElem = new T[10]; }
    CArray1D(int size);
	CArray1D(const CArray1D<T>& v);
	~CArray1D() {delete [] m_pElem;};
    // [] operator;
	T& operator[](int i) const {
		assert(i >=0 && i < m_nSize);
		return m_pElem[i];
	}
	// = operator;
	CArray1D<T>& operator=(const CArray1D<T>& v);
	// + operator;
	CArray1D<T> operator+() const;
    CArray1D<T> operator+(const CArray1D<T>& v);
	// - operator;
	CArray1D<T> operator-() const;
	CArray1D<T> operator-(const CArray1D<T>& v);
	// +=operator;
	CArray1D<T>& operator+=(const CArray1D<T>& v);
    // * operator;
	CArray1D<T> operator*(const CArray1D<T>& v);
	// size;
	int mSize() const;
	void print(std::ostream& out) const;
	void mResize(int size){
        m_nSize = size;
		delete [] m_pElem;
		m_pElem = new T[m_nSize];
	}
};

template<typename T>
CArray1D<T>::CArray1D(int size):
	m_nSize(size){
	m_pElem = new T[m_nSize];
}

template<typename T>
CArray1D<T>::CArray1D(const CArray1D<T>& v){
	m_nSize = v.m_nSize;
	m_pElem = new T[m_nSize];
	for(int i = 0; i < m_nSize; i ++){
		m_pElem[i] = v.m_pElem[i];
	}
}

template<typename T>
int CArray1D<T>::mSize() const{
	return this->m_nSize; 
}

template<typename T>
CArray1D<T>& CArray1D<T>::operator=(const CArray1D& v){
	if(this != &v){
		m_nSize = v.m_nSize;
		delete [] m_pElem;
		m_pElem = new T[m_nSize];

		for(int i = 0; i < m_nSize; i++){
			m_pElem[i] = v.m_pElem[i];
		}
	}
	return *this;
}

template<typename T>
CArray1D<T> CArray1D<T>::operator+() const{
	CArray1D<T> tmp(m_nSize);
    for(int i = 0; i < m_nSize; i ++)
		tmp.m_pElem[i] = abs(m_pElem[i]);
	return tmp;
}

template<typename T>
CArray1D<T> CArray1D<T>::operator-() const{
	CArray1D<T> tmp(m_nSize);
    for(int i = 0; i < m_nSize; i ++)
		tmp.m_pElem[i] = -(m_pElem[i]);
	return tmp;

}

template<typename T>
CArray1D<T> CArray1D<T>::operator+(const CArray1D& v){
	assert(m_nSize == v.m_nSize);
	CArray1D<T> tmp(m_nSize);
	for(int i = 0; i < m_nSize; i ++)
        tmp.m_pElem[i] = v.m_pElem[i] + m_pElem[i];
	return tmp;
}

template<typename T>
CArray1D<T> CArray1D<T>::operator-(const CArray1D& v){
	assert(m_nSize == v.m_nSize);
	CArray1D<T> tmp(m_nSize);
	for(int i = 0; i < m_nSize; i ++)
        tmp.m_pElem[i] =m_pElem[i] - v.m_pElem[i];
	return tmp;
}

template<typename T>
CArray1D<T> CArray1D<T>::operator*(const CArray1D& v){
	assert(v.m_nSize == m_nSize);
	CArray1D<T> tmp(m_nSize);
	for(int i = 0; i < m_nSize; i ++)
        tmp.m_pElem[i] = m_pElem[i] * v.m_pElem[i];
	return tmp;
}

template<typename T>
CArray1D<T>& CArray1D<T>::operator+=(const CArray1D& v){
	assert(v.m_nSize == m_nSize);
	for(int i = 0; i < m_nSize; i ++)
        m_pElem[i] += v.m_pElem[i];
	return *this;
}


template<typename T>
void CArray1D<T>::print(std::ostream& out) const{
	for(int j = 1; j <= m_nSize; j ++){
		out << m_pElem[j - 1] << ' ';
	    if( 0 == j % 5)
			out << std::endl;
	}
    out << std::endl;
}
#endif
#ifndef LINEARLIST_HHH
#define LINEARLIST_HHH

template<typename T> 
class CLinearList{
private:
	// data;
    T* m_pData;
	int m_nLength;
	int m_nSize;
public:
	// constructors;
	CLinearList(int size = 10);
    // methods;
	bool mFind(const int& k, T& data) const;
	int mSearch(const T& data) const;
	CLinearList<T>& mAdd(const int& k, const T& data);
	CLinearList<T>& mDelete(const int& k, T& data);
	~CLinearList();
	int mLength() const;
	int mSize() const;
	void print() const;
};

#include "linearlist.h"
#include <assert.h>
// default constructor;
// constructor;
template<typename T>
CLinearList<T>::CLinearList(int size = 100):
    m_nLength(0), m_nSize(size){
	m_pData = new T[m_nSize];
}
// de-constructor;
template<typename T>
CLinearList<T>::~CLinearList(){
	delete [] m_pData;
	m_pData = NULL;
}

template<typename T>
bool CLinearList<T>::mFind(const int& k, T& data) const{
    if( k < 0 && k > m_nLength)
		return false;
	data = m_pData[k - 1];
	return true;
}

template<typename T>
int CLinearList<T>::mSearch(const T& data) const{
	for(int i = 0; i < m_nLength; i ++){
        if(data == m_pData[i])
			return i ++;
	}
	return 0;
}

template<typename T>
CLinearList<T>& CLinearList<T>::mAdd(const int& k, const T& data){
	assert(k >= 0 && k <= m_nLength);
	if(m_nLength != 0)
		assert(m_nLength < m_nSize);
    for(int i = m_nLength - 1; i >= k; i --){
	    m_pData[i + 1] = m_pData[i];
	}
	m_pData[k] = data;
	m_nLength ++;
	return *this;
}

template<typename T>
CLinearList<T>& CLinearList<T>::mDelete(const int& k, T& data){
	assert(k >= 1 && k < m_nLength);
	data = m_pData[k - 1];
	for(int i = k - 1 ; i < m_nLength ; i ++){
        m_pData[i] = m_pData[i + 1];
	}
    return *this;

}

template<typename T>
int CLinearList<T>::mLength() const{
	return m_nLength;
}

template<typename T>
int CLinearList<T>::mSize() const{
	return m_nSize;
}
#endif
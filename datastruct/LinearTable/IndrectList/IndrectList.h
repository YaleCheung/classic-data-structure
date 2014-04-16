/**
 *@Program: indirect list;
 *@Author:  zhangyi;
 *@Date:    2013.11.22
 *@Version: 1.0
 **/
#ifndef INDIRECTLIST_HH
#define INDIRECTLIST_HH

#include <stdio.h>

template<typename T>
class CIndrectList{
private:
	// pointe to a potiner which point to a T type object;
    T** m_ppTable;
	// length of CurrentIndrectList;
	unsigned int m_nLength;
	unsigned int m_nsize;
public:
	// constructor;
	CIndrectList(int size);
	~CIndrectList();
    // methods;
	// Insert;
	CIndrectList& mInsert(int k, const T& data);
	// Delete;
	CIndrectList& mDelete(int k, const T& data);
	// find;
	bool mFind(int k, const T& data) const;
    // length;
	int mLength() const;
	// size;
    int mSize() const;
}; // CIndrectList;

// implement;
// constructors;
template<typename T>
CIndrectList<T>::CIndrectList(int size = 10):
	m_nLength(0),m_nSize(size){
	m_ppTable = new T*[m_nSize];
}
template<typename T>
CIndrectList<T>::~CIndrectList(){
	for(int i = 0; i < m_nLength; i ++)
		delete m_ppTable[i];
	delete [] m_ppTable;
}

// Insert data after (k-1)th element;
template<typename T>
CIndrectList<T>& CIndrectList<T>::mInsert(int k, const T& data){
	if(m_nLength == m_nsize)
		printf("Not enough Space\n");
	if( k < 0 || k > m_nLength)
		printf("Input wrong index in Insert\n;");
	// move elements to contain k;
	for(int i = m_nLength - 1; i >= k; i --){
		m_ppTable[i + 1] = m_ppTable[i]; 
	}
	// add data;
	m_ppTable[k] = new T;
	*m_ppTable[k] = data;
	m_nLength ++;
	return *this;
}
// Delete;
template<typename T>
CIndrectList<T>& CIndrectList<T>::mDelete(int k, const T& data){
	if(k > m_nLength || k < 0)
		printf("Input wrong index in Delete\n;");
	if(mFind(k,data)){
	    delete m_ppTable[k - 1];
		for(int i = m_nLength - 1; i >= k; i --)
		    m_ppTable[i] = m_ppTable[i + 1];
	    m_nLength --£»
	}
    return *this;
}

template<typename T>
bool CIndrectList<T>::mFind(int k, const T& data) const{
	if(k > m_nLength || k < 0)
		printf("Input wrong index in Find\n;");
	return (*(m_ppTable[i]) == data) ? true : false;
}

template<typename T>
int CIndrectList<T>::mLength() const{
	return m_nLength;
}

template<typename T>
int CIndrectList<T>::mSize() const{
	return m_nSize;
}
#endif
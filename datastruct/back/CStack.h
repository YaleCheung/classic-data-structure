#ifndef CSTACK_HHH
#define CSTACK_HHH

#include <cassert>

template<typename T>
class CStack{
private:
	// members;
	T* m_pData;
	int m_nLength;
	int m_nSize;
public:
	// constructors;
	CStack(int size = 100);
	~CStack();
	// methods;
	bool mIsEmpty() const;
	bool mIsFull() const;
	T mTop() const;
	CStack<T>& mAdd(const T& x);
	CStack<T>& mDelete();
};

template<typename T>
CStack<T>::CStack(int size):
    m_nSize(size){
	m_pData = new T[m_nSize];
	m_nLength = 0;
}

template<typename T>
CStack<T>::~CStack(){
	delete [] m_pData;
}

template<typename T>
bool CStack<T>::mIsEmpty() const{
	return (m_nLength > 0) ? false : true;
}
template<typename T>
bool CStack<T>::mIsFull() const{
	return (m_nSize == m_nLength) ? true : false;
}
template<typename T>
CStack<T>& CStack<T>::mAdd(const T& tmp){
	if(m_nLength == m_nSize){
		m_nSize *= 2;
		T* pTmpData = new T[m_nSize];
		for(int i = 0; i < (m_nSize / 2); i ++)
			pTmpData[i] = m_pData[i];
		delete [] m_pData;
		m_pData = pTmpData;
	}
	m_pData[m_nLength] = tmp;
	m_nLength ++;
	return *this;
} 

template<typename T>
CStack<T>& CStack<T>::mDelete(){
	if(m_nLength > 0){
		m_nLength --;
	}
	return *this;
}

template<typename T>
T CStack<T>::mTop() const{
	assert(m_nLength > 0);
	return m_pData[m_nLength - 1];
}
#endif
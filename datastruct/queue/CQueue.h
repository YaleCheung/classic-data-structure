#ifndef CQUEUE_HHH
#define CQUEUE_HHH
#include<cassert>


template<typename T>
class CQueue{
private:
	// members;
	int m_nFront;
	int m_nRear;
	int m_nSize;
	T* m_pElem;
public:
	// constructors;
	CQueue(const int& maxsize = 100);
	~CQueue();
    
	// methods;
	CQueue<T>& mAdd(const T& data);
	CQueue<T>& mDelete();

	T mFirst() const;
	T mLast() const;
	bool mIsEmpty() const;
	bool mIsFull() const;
}; // CQueue End;

template<typename T>
CQueue<T>::CQueue(const int& maxsize):
    m_nFront(0), m_nRear(0), m_nSize(maxsize){
	m_pElem = new T[maxsize];
}

template<typename T>
CQueue<T>::~CQueue(){
	delete [] m_pElem;
}

template<typename T>
bool CQueue<T>::mIsFull() const{
	return ((m_nRear + 1) % m_nSize == m_nFront) ? true : false;
}

template<typename T>
bool CQueue<T>::mIsEmpty() const{
	return (m_nFront == m_nRear) ? true : false;
}

template<typename T>
CQueue<T>& CQueue<T>::mAdd(const T& data){
    assert((m_nRear + 1) % m_nSize != m_nFront);
	m_pElem[m_nRear] = data;
	m_nRear = (m_nRear + 1) % m_nSize;
	return *this;
}

template<typename T>
CQueue<T>& CQueue<T>::mDelete(){
	assert(m_nRear != m_nFront);
	m_nFront = (m_nFront + 1) % m_nSize;
	return *this;
}
template<typename T>
T CQueue<T>::mFirst() const{
    assert(m_nRear != m_nFront);
	return m_pElem[m_nFront];
}

template<typename T>
T CQueue<T>::mLast() const{
    assert(m_nRear != m_nFront);
    if(m_nRear == 0)
		return m_pElem[m_nSize - 1];
	else
		return m_pElem[m_nRear - 1];
}
// define end;

#endif
#ifndef CLINKQUEUE
#define CLINKQUEUE
#include <assert.h>
#include <stdio.h>

template<typename T>
class CLinkQueue;

template<typename T>
struct SNode{
	friend class CLinkQueue<T>;
private:
	SNode<T>* m_pNext;
	T m_nData;
public:
	SNode();
	SNode(const T& data);
    ~SNode();
};

template<typename T>
SNode<T>::SNode():
	m_pNext(NULL) {}

template<typename T>
SNode<T>::SNode(const T& data):
	m_pNext(NULL), m_nData(data) {}

template<typename T>
SNode<T>::~SNode(){
    m_pNext = NULL;
}


template<typename T>
class CLinkQueue{
private:
	// members;
	SNode<T>* m_pFront;
	SNode<T>* m_pRear;
public:
	// constructor;
    CLinkQueue();
	~CLinkQueue();
    // methods;    
	CLinkQueue& mAdd(const int& data);
	CLinkQueue& mDelete();
    T mFirst() const;
	T mLast() const;
	bool mIsEmpty() const;
};

template<typename T>
CLinkQueue<T>::CLinkQueue():
	m_pFront(NULL), m_pRear(NULL){}

template<typename T>
CLinkQueue<T>::~CLinkQueue(){
	while(m_pFront != m_pRear){
		SNode<T>* tmp = m_pFront;
		m_pFront = m_pFront -> m_pNext;
		delete tmp;
	}
}

template<typename T>
CLinkQueue<T>& CLinkQueue<T>::mAdd(const int& data){
	SNode<T>* tmp = new SNode<T>(data);
	if(m_pFront){
		m_pRear -> m_pNext = tmp;
		m_pRear = m_pRear -> m_pNext;
	}else
	    m_pFront = m_pRear = tmp;
    return *this;	
}

template<typename T>
CLinkQueue<T>& CLinkQueue<T>::mDelete(){
	if(m_pFront != NULL){
		SNode<T>* tmp = m_pFront;
		m_pFront = m_pFront -> m_pNext;
		delete tmp;
	}
    return *this;
}

template<typename T>
bool CLinkQueue<T>::mIsEmpty() const{
	return (m_pFront == NULL) ? true : false;
}

template<typename T>
T CLinkQueue<T>::mFirst() const{
    assert(m_pFront != NULL);
	return m_pFront -> m_nData;
}

template<typename T>
T CLinkQueue<T>::mLast() const{
	assert(m_pRear != NULL);
	return m_pRear -> m_nData;
}
#endif
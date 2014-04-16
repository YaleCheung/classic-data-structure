#include <stdio.h>
#include <assert.h>

template<typename T>
struct CLinkStack;

template<typename T>
struct SNode{
	friend CLinkStack<T>;
public:
	SNode();
	SNode(const T& data);
private:
	// members;
	T m_nData;
	SNode<T>* m_pNext;
};

template<typename T>
SNode<T>::SNode():
	m_pNext(NULL){}

template<typename T>
SNode<T>::SNode(const T& data):
	m_nData(data), m_pNext(NULL) {}
	
template<typename T>
class CLinkStack{
private:	
    SNode<T>* m_pTop;

public:
	// constructors;
    CLinkStack();
	~CLinkStack();
    // methods;
	T mTop() const;

    CLinkStack<T>& mAdd(const T& data);
	CLinkStack<T>& mDelete();
    
	T mFirst() const;
	T mLast() const;

	bool mIsEmpty() const;
};

template<typename T>
CLinkStack<T>::CLinkStack(){
	m_pTop = NULL;
}

template<typename T>
CLinkStack<T>::~CLinkStack(){
	while(m_pTop != NULL){
       SNode<T>* pTmp = m_pTop;
	   m_pTop = m_pTop -> m_pNext;
	   delete pTmp;
	}
}

template<typename T>
CLinkStack<T>& CLinkStack<T>::mAdd(const T& data){
    SNode<T>* pTmp = new SNode<T>(data);
	pTmp -> m_pNext = m_pTop;
	m_pTop = pTmp;
	return *this;
}

template<typename T>
CLinkStack<T>& CLinkStack<T>::mDelete(){
	if(m_pTop != NULL){
	    SNode<T>* pTmp = m_pTop;
		m_pTop = m_pTop -> m_pNext;
		delete [] pTmp;
	}
    return *this;
}

template<typename T>
bool CLinkStack<T>::mIsEmpty() const{
    return ((m_pTop == NULL) ? true : false);
}

template<typename T>
T CLinkStack<T>::mTop() const{
	assert(m_pTop != NULL);
	return m_pTop->m_nData;
}
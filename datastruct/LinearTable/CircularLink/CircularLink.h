/**
 *@Program: circular link with a head;
 *@Author:  zhangyi;
 *@Date:    2013.11.22
 *@Version: 1.0
 **/
#ifndef CIRCULARLINK_HHH
#define CIRCULARLINK_HHH

template<typename T>
class CCircularLink;

template<typename T>
struct SNode
{
friend CCircularLink<T>;
private:
	T m_nData;
	SNode<T>* m_pNext;
public:
	SNode();
	SNode(T data);
	~SNode();
}; // SNode;

// CCircularLink with a head;
template<typename T>
class CCircularLink{
private:
	// data fields;
	SNode<T>* m_pHead;
public:
	// constructors;
    CCircularLink();
	~CCircularLink();

	// methods;
	void mInsert(const T& data);
    bool mFind(const T& data) const;
	int mDelete();
};  // CCircularLink;

// SNode;
template<typename T>
SNode<T>::SNode():
	m_pNext(NULL){}


template<typename T>
SNode<T>::SNode(T data):
	m_nData(data),m_pNext(NULL){}

template<typename T>
SNode<T>::~SNode() {}


// CCircularLink;
template<typename T>
CCircularLink<T>::CCircularLink(){
	m_pHead = new SNode<T>;
	m_pHead -> m_pNext = m_pHead;
}

template<typename T>
CCircularLink<T>::~CCircularLink(){
	if(m_pHead != NULL){
        SNode<T>* pTmp = m_pHead -> m_pNext;
		while(pTmp != m_pHead){
			SNode<T>* p;
			p = pTmp -> m_pNext;
            delete pTmp;
			pTmp = p;
		}
	    delete m_pHead;
    }
}
// method;
// Insert;
template<typename T>
void CCircularLink<T>::mInsert(const T& data){
	if(NULL != m_pHead){
        SNode<T>* pTmp = m_pHead -> m_pNext;
		SNdde<T>* pInsert = new SNdde<T>(data);
		pInsert -> m_pNext = pTmp;
		m_pHead -> m_pNext = pInsert;
	}
}
// method;
// Delete;
int CCircularLink<T>::mDelete(){
	if(NULL != m_pHead){
        SNode<T> pTmp = m_pHead -> m_pNext;
		if(m_pHead != pTmp){
            m_pHead -> m_pNext = pTmp -> m_pNext;
			delete pTmp;
			return 1;
	    }
		return -1;
    }
	return -1;
}

// method;
// find;
template<typename T>
bool CCircularLink<T>::mFind(const T& data) const{
	if(NULL != m_pHead){ 
	    SNode<T>* pTmp = m_pHead -> m_pNext;
        while(m_pHead != pTmp){
             if(pTmp -> m_nData == data)
		         return true;
        }
		return false;
}
#endif

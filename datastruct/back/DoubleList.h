#ifndef DOUBLELIST_HHH
#define DOUBLELIST_HHH

#include <stdio.h>

template<typename T>
class CDoubleList;

template<typename T>
struct SDNode{
private:
    T m_nData;
	SDNode* m_pLeft;
	SDNode* m_pRight;
public:
	// constructors;
	friend CDoubleList<T>;
	SDNode();
	SDNode(const T& data);
	~SDNode();
};


template<typename T>
class CDoubleList{
public:
	// constructors;
	CDoubleList();
	~CDoubleList();
	// methods;
	// Length;
    int mLength() const;
	// Find;
	bool mFind(const T& data) const;
	// Delete;
	CDoubleList<T>& mDelete(int k, const T& data);
	// Insert;
	CDoubleList<T>& mInsert(int k, const T& data);
private:
	SDNode<T>* m_pHead;
	SDNode<T>* m_pLast;
};


template<typename T>
SDNode<T>::SDNode():
	m_pLeft(NULL), m_pRight(NULL) {}


template<typename T>
SDNode<T>::SDNode(const T& data):
	m_pLeft(NULL), m_pRight(NULL) {
    m_nData = data;
}

template<typename T>
SDNode<T>::~SDNode(){}

template<typename T>
CDoubleList<T>::CDoubleList(){
	m_pHead = new SDNode<T>;
	m_pLast = new SDNode<T>;
	m_pHead -> m_pLeft = NULL;
	m_pHead -> m_pRight = m_pLast;
	m_pLast -> m_pLeft = m_pHead;
	m_pLast -> m_pRight = NULL;
}

template<typename T>
CDoubleList<T>::~CDoubleList(){
	SDNode<T>* pTmp;
	while(m_pHead != m_pLast){
         pTmp = m_pHead -> m_pRight;
		 delete m_pHead;
		 m_pHead = pTmp;
	}
	if(m_pLast != NULL)
		delete m_pLast;
}

template<typename T>
CDoubleList<T>& CDoubleList<T>::mInsert(int k, const T& data){
	SDNode<T>* pTmp = m_pHead;
	if(k < 0)
		printf("Wrong input of Insert\n");
	else{
	        while(k > 0){
			    pTmp = pTmp -> m_pRight;	
                k --;
				if(pTmp == m_pLast)
                    break;
			}
			if(k != 0)
				printf("k is too large to insert\n");
			if(k == 0){
                SDNode<T>* pInsert = new SDNode<T>(data);
                SDNode<T>* pPar = pTmp->m_pLeft; 

                pPar -> m_pRight = pInsert;
				pInsert -> m_pLeft = pPar;

				pTmp -> m_pLeft = pInsert;
				pInsert -> m_pRight = pTmp;
			}
	}
	return *this;
}

template<typename T>
CDoubleList<T>& CDoubleList<T>::mDelete(int k, const T& data){
    SDNode<T>* pTmp = m_pHead;
	while(k > 0){
		pTmp = pTmp -> m_pRight;
		k --;
		if(pTmp == m_pLast)
			break;
	}
    
	if(k > 0)    // pTmp == m_pLast;
		printf("No data can find to delete\n");
	else{
		if(pTmp == m_pLast)
			printf("No data can find to delete\n");
        if(data == pTmp -> m_nData){
			printf("delete data find\n");
			SDNode<T>* pPar = pTmp -> m_pLeft;
			SDNode<T>* pNext = pTmp -> m_pRight;
            
			delete pTmp;

			pPar -> m_pRight = pNext;
			pNext -> m_pLeft = pPar;
		}

	}
	return *this;
}


template<typename T>
int CDoubleList<T>::mLength() const{
	SDNode<T>* pTmp = m_pHead -> m_pRight;
	int i = 0;
	while(pTmp != m_pLast){
		pTmp = pTmp -> m_pRight;
		i ++;
	}
    return i;
}

template<typename T>
bool CDoubleList<T>::mFind(const T& data) const{
	SDNode<T>* pTmp = m_pHead;
	while(pTmp != m_pLast){
		pTmp = pTmp -> m_pRight;
		if(data == pTmp -> m_nData)
			return true;
	}
	return false;
}
#endif
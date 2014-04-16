
#include <stdio.h>
#include <cassert>

template<typename T>
class CLinearLink;

template<typename T>
struct SNode
{
friend CLinearLink<T>;
private:
	T m_nData;
	SNode<T>* m_pNext;
public:
	SNode();
	SNode(T data);
	~SNode();
};

template <typename T>
class CLinearLink{
private:
	// Data;
	SNode<T>* m_pHead;
public:
	// constructors;
	CLinearLink();
	~CLinearLink();
	// methods;
	CLinearLink<T>& mInsert(const int& k, const T& data);
	CLinearLink<T>& mDelete(const int& k, T& data);
	bool mFind(const int& k, T& data) const;
	int mSearch(const T& data);
	
	void mBinSort(const int& range);
}; 
template<typename T>
SNode<T>::SNode():
	m_pNext(NULL){}


template<typename T>
SNode<T>::SNode(T data):
	m_nData(data),m_pNext(NULL){}

template<typename T>
SNode<T>::~SNode() {}


// defination;
// constructors;
template<typename T>
CLinearLink<T>::CLinearLink():
    m_pHead(NULL){} 

template<typename T>
CLinearLink<T>::~CLinearLink(){
	SNode<T>* pTmp = NULL;
	while(m_pHead){
	       pTmp = m_pHead;
           m_pHead = m_pHead -> m_pNext;
	       delete pTmp;
	       pTmp = NULL;
	}
}
// methods;
// Insert;
template<typename T>
CLinearLink<T>& CLinearLink<T>::mInsert(const int& k, const T& data){
	assert(k >=0);
	SNode<T>* pPre = m_pHead;
	for(int i = 1; i < k && pPre; i ++)
		pPre = pPre -> m_pNext;
	SNode<T>* pInsert = new SNode<T>(data);
	if(k > 0 && (pPre != NULL)){
		pInsert -> m_pNext = pPre -> m_pNext;
		pPre -> m_pNext = pInsert;
	}else{
        pInsert -> m_pNext = m_pHead;
		m_pHead = pInsert;
	}
	return *this;
}

// methods;
// Delete;
template<typename T>
CLinearLink<T>& CLinearLink<T>::mDelete(const int& k, T& data){
	assert(k > 0 && m_pHead != NULL);
    SNode<T>* pPre = m_pHead;
    // delete about head;
	SNode<T>* pDelete = m_pHead;
	if(1 == k)
		m_pHead = m_pHead -> m_pNext;
	else{
		for(int i = 1; i < k - 1 && (pPre != NULL); i ++){
		    pPre = pPre -> m_pNext; 
		}
        assert(pPre && pPre->m_pNext);
		pDelete = pPre -> m_pNext;
		pPre -> m_pNext = pDelete -> m_pNext;
	}
	data = pDelete ->m_nData;
	delete pDelete;
	return *this;
}

// methods;
// Find;
	//bool mFind(const int& k, T& data) const;
template<typename T>
bool CLinearLink<T>::mFind(const int& k, T& data) const{
	SNode<T>* pTmp = m_pHead;
	assert(k > 0 && k <= m_nLength);
    int i = 1;
	while( i < k && pTmp != NULL){
		pTmp = pTmp -> m_pNext;
		i ++;
	}
    if(NULL != pTmp -> m_pNext)
		pTmp->m_nData = data;
	else
		return false;
	return true;
}

template<typename T>
int CLinearLink<T>::mSearch(const T& data){
    int i = 1;
	SNode<T>* pTmp = m_pHead;
	while(pTmp){

		if(pTmp->m_nData == data)
			return i;
        pTmp = pTmp -> m_pNext;
		i ++;
	}
	return -1;
}

// binSort;
template<typename T>
void CLinearLink<T>::mBinSort(const int& range){
	// pBegins records the beginning of each bin;
    SNode<T>** pBegins = new SNode<T>*[range + 1]; 
	// pEnds records the ends of each bin;
	SNode<T>** pEnds = new SNode<T>*[range + 1];
    
	for(int i = 0; i <= range; i++)
		pBegins[i] = NULL;
    SNode<T>* pTmp = m_pHead;
	for(; pTmp; pTmp = pTmp -> m_pNext){
		int data = pTmp -> m_nData; 
		// pBegins is NULL means the bin is empty;
		if(pBegins[data]){
			pEnds[data] -> m_pNext = pTmp;
			pEnds[data] = pTmp;
		}else
			pBegins[data] = pEnds[data] = pTmp;
	}
	// collect into a new link using the thought of bin sort;
	pTmp = NULL;
    for(int i = 0; i < range; i ++){
		if(pBegins[i]){
			if(pTmp)
				pTmp -> m_pNext = pBegins[i];
			// if pTmp is NULL, that must be the 0th bin ;
			else
				m_pHead = pBegins[i];
		    pTmp = pEnds[i];
		}
	}
	if(pTmp)
		pTmp -> m_pNext = NULL;	
	delete [] pBegins;
	delete [] pEnds;
}

#ifndef SPACEPOOL_HHH 
#define SPACEPOOL_HHH
//declaration;

template<typename T>
class CSpacePool;


template<typename T>
struct SPoolNode{
	// members;
private:
    T m_nData;
    int m_nNextIndex;
public:
	// constructors;
	friend class CSpacePool<T>;
};  //SPoolNode;

template<typename T>
class CSpacePool{
private:
	// members;
	int m_nSpaceSize;            // max number of nodes could be allocated;
	int m_nFirstUseableIndex;    // the first useable node.
	SPoolNode<T>* m_pNode;       // data table;
public:
	// constructors;
    CSpacePool(int maxsize);
	~CSpacePool();

	// methods;
	int mAllocate();             // allocate a space;
    void mDeAllocate(int& i);    // deallocate the (i+1)th node;
};  // CSpacePool;


// de-constructors;
template<typename T>
CSpacePool<T>::CSpacePool(int maxsize = 100){
	m_nSpaceSize = maxsize;
	m_pNode = new SPoolNode<T>[m_nSpaceSize];

	for(int i = 0; i < m_nSpaceSize; i ++){
		m_pNode[i].m_nNextIndex = i + 1;
	}
    m_pNode[m_nSpaceSize].m_nNextIndex = -1;    
	m_nFirstUseableIndex = 0;
}

template<typename T>
CSpacePool<T>::~CSpacePool(){
    delete [] m_pNode;
}

template<typename T>
int CSpacePool<T>::mAllocate(){
    if(-1 == m_nFirstUseableIndex){
		printf("Space is full, Cannot alloc\n");
	    return -1;
    }else{
		int ret = m_nFirstUseableIndex;
		m_nFirstUseableIndex = m_pNode[m_nFirstUseableIndex].m_nNextIndex;
		return m_nFirstUseableIndex;
	}
}

template<typename T>
void CSpacePool<T>::mDeAllocate(int& i){
    m_pNode[i].m_nNextIndex = m_nFirstUseableIndex;
	m_nFirstUseableIndex = i;
	i = -1;
}
#endif
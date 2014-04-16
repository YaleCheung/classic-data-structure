#include <stdio.h>
#include <assert.h>
template<typename T>
class CMaxHeap{
public:
	// constructors;
	CMaxHeap(const size_t& maxsize = 100);
	~CMaxHeap();
	// methods;
	CMaxHeap<T>& mInsert(const T& elem);
	CMaxHeap<T>& mDeleteMax(T& elem);
	void mInitialize(T array[], size_t cursize, size_t maxsize);
	void mPrint();
private:
	void _mExchange(size_t i, size_t j){
	//exchange the index i and j in m_pHeap;
		if( i > m_nCurSize - 1 || j > m_nCurSize - 1)
			return;
		T tmp = m_pHeap[i];
		m_pHeap[i] = m_pHeap[j];
		m_pHeap[j] = tmp;
	}
	// members;
	T* m_pHeap;
    size_t m_nCurSize; 
	size_t m_nMaxSize;

};

template<typename T>
CMaxHeap<T>::CMaxHeap(const size_t& maxsize):
    m_nMaxSize(maxsize), m_nCurSize(0){
    assert(m_nMaxSize > 0);
	m_pHeap = new T[m_nMaxSize];	
}

template<typename T>
CMaxHeap<T>::~CMaxHeap(){
	delete [] m_pHeap;
	m_pHeap = NULL;
}

template<typename T>
CMaxHeap<T>& CMaxHeap<T>::mInsert(const T& elem){
    if(m_nCurSize == m_nMaxSize)
		return *this;
	m_nCurSize ++;
	size_t i = m_nCurSize - 1;
    while(i != 0 && elem > m_pHeap[i / 2]){
		m_pHeap[i] = m_pHeap[i / 2];
		i = i / 2;
	}
	m_pHeap[i] = elem; 
	return *this;
}

template<typename T>
CMaxHeap<T>& CMaxHeap<T>::mDeleteMax(T& elem){
	assert(m_nCurSize != 0);
    elem = m_pHeap[0];
    T tmp = m_pHeap[m_nCurSize - 1];
	m_nCurSize --;

	int i = 0;
	int j = 1;
	while(i <= m_nCurSize - 1){
        if(m_pHeap[j] < m_pHeap[j + 1] && i < (m_nCurSize - 1))
			j ++;
		if(tmp > m_pHeap[j])
			break;
		m_pHeap[i] = m_pHeap[j];
		i = j;
		j = 2 * j + 1;
	}
    m_pHeap[i] = tmp;
	return *this;	
}

template<typename T>
void CMaxHeap<T>::mInitialize(T array[], size_t cursize, size_t maxsize){
	delete m_pHeap;
	m_nCurSize = cursize;
	m_nMaxSize = maxsize;
	m_pHeap = new T[maxsize];
	for(size_t i = 0; i < cursize; i ++)
		m_pHeap[i] = array[i];
    
	for(int i = m_nCurSize  / 2 - 1; i >= 0; i --){
		int j = i;
		T tmp = m_pHeap[j];
		while(j <= m_nCurSize - 1){
			int k = 2 * j + 1;  // lchild index
			if(k < (m_nCurSize - 1) && m_pHeap[k] < m_pHeap[k + 1]) {
				k ++;
			}
			if(tmp > m_pHeap[k])
				break;
			m_pHeap[j] = m_pHeap[k];
			j = k;
			k = 2 * k + 1;
		}
		m_pHeap[j] = tmp;
	}
}

template<typename T>
void CMaxHeap<T>::mPrint(){
	for(size_t i = 0; i < m_nCurSize; i ++)
		printf("%d\t", m_pHeap[i]);
	printf("\n");
}
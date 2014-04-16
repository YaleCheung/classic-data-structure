/**
 *@ Program: hash table with open addressing method;
 *@ Author:  zhangyi;
 *@ Date:    2013.12.21;
 *@ Version: 1.0
 **/
#include <cassert>
#include <iostream>
template<typename K, typename E = int> 
class CHashTable{
private:
	// members;
    bool* m_pEmpty;
	E* m_pArray;
	size_t m_nSize;
public:
	// constructors;
	CHashTable(size_t size = 100);
	~CHashTable();
	// methods;
    CHashTable& mInsert(const K& key, const E& elem);
    bool mFind(const K& key, const E& elem);
private:
	int _mHashFunc(const K& key);
};

template<typename K, typename E>
CHashTable<K,E>::CHashTable(size_t size):
	m_nSize(size){
    // initialize the m_pEmpty
    assert(m_nSize > 0);
    m_pEmpty = new bool[size];
	for(int i = 0; i < size; i ++)
		m_pEmpty[i] = true;
    m_pArray = new E[size];
}

template<typename K, typename E>
CHashTable<K,E>::~CHashTable(){
	delete [] m_pArray;
	delete [] m_pEmpty;
}

template<typename K, typename E>
int CHashTable<K,E>::_mHashFunc(const K& key){
	return key % m_nSize;
}
template<typename K, typename E>
CHashTable<K,E>& CHashTable<K,E>::mInsert(const K& key, const E& elem){
	int i = _mHashFunc(key);
    int j = i;

    if(!m_pEmpty[j]){
		do{
            j = (j + 1) % m_nSize;
			if(m_pEmpty[j])
				break;
		} while(j != i);
		if(j == i){
			printf("FULL!!!\n");
			return *this;
		}
	}
    m_pArray[j] = elem;
	m_pEmpty[j] = false;
    return *this;
}

template<typename K, typename E>
bool CHashTable<K,E>::mFind(const K& key, const E& elem){
	int i = _mHashFunc(key);
	int j = i;
	if(m_pArray[j] != elem || m_pEmpty[j]){
		do{
            j = (j + 1) % m_nSize;
			if(!m_pEmpty[j] && m_pArray[j] == elem)
				break;
		} while(j != i);
		if(j == i)
			return false;
	}
	return true;
}
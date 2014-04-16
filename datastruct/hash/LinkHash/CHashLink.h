#include "CLinearLink.h"

template<typename K, typename E>
class CHashLink{
private:
	// members;
	int m_nSize;
    CLinearLink<E>* m_pLinks;
public:
	// constructors;
	CHashLink(const int& size = 100):
	    m_nSize(size){
        m_pLinks = new CLinearLink[m_nSize];	
	}
	~CHashLink(){
		delete [] link;
	}

	// methods;
	CHashLink<K,E>& mInsert(const K& key, const E& elem){
		int pos = key % m_nSize;
		m_pLinks[pos].mInsert(0,key);
		return *this;
	}
	CHashLink<K,E>& mDelete(const K& key, const E& elem){
		int pos = key % m_nSize;
		m_pLinks[pos].mDelete(elem);
		return *this;
	}
	bool mSearch(const K& key, const E& elem){
		int pos = key % m_nSize;
        return m_pLinks.mSearch(key);
	}
};

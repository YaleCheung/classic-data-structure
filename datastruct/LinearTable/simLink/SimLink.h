
#include "SpacePool.h"

template<typename T, int SpaceSize = 100>
class CSimLink{
private:
	// members;
	CSpacePool<T> space(SpaceSize);
	int firstNodeIndex;
public:
	// constructors;
	CSimLink(){
		firstNodeIndex = -1;
	}
	~CSimLink(){
    
	}

	// methods;
	CSimLink<T>& mInsert(int k, const T& data){
        if(k < 0){
			printf("Wrong in k or the Space is full\n");
		    return *this;
		}
		int p = firstNodeIndex;
        for(int i = 1; i != k; i ++)
			space.


	}
    CSimLink<T>& mDelete(int k, const T& data){
	}
	bool Find(int k, const T& data){
	}
	int length() const{
	}
};  // CSimLink;
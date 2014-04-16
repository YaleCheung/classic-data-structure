#ifndef NODE_HHH
#define NODE_HHH

template<typename T>
struct SNode
{
private:
	T m_nData;
	SNode<T>* m_pNext;
public:
	SNode();
	SNode(T data);
	~SNode();
};


template<typename T>
SNode<T>::SNode():
	m_pNext(NULL){}


template<typename T>
SNode<T>::SNode(T data):
	m_nData(data),m_pNext(NULL){}

template<typename T>
SNode<T>::~SNode() {}
#endif
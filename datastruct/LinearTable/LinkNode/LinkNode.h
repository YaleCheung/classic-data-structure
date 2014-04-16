#ifndef NODE_HHHH
#define NODE_HHHH

template<typename T>
struct SLinkNode{
	T m_nData;
	SLinkNode<T>* m_pNode;
	SLinkNode();
	~SLinkNode();
	SLinkNode(const T& data);
};

#endif
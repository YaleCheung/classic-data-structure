#include "LinkNode.h"
template<typename T>
SLinkNode<T>::SLinkNode():
	m_pNode(0) {}

template<typename T>
SLinkNode<T>::SLinkNode(const T& data):
	m_nData(data), m_pNode(0) {}

template<typename T>
SLinkNode<T>::~SLinkNode() {}

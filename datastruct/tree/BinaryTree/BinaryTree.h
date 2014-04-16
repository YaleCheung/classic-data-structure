/**
 *@ Program: the basic implement of BinaryTree;
 *@ Author:  zhangyi;
 *@ Version: 1.0
 *@ Date:    2013.12.26
 **/
#define NULL 0
#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>

using std::endl;
using std::cout;
using std::queue;

template<typename T>
class CBinaryTree;

template<typename T>
struct SBinaryNode{
	friend class CBinaryTree<T>;
private:
    T m_nData;
    SBinaryNode<T>* m_pLeft;
	SBinaryNode<T>* m_pRight;
public:
	SBinaryNode(T data):
	    m_nData(data){
			m_pLeft = NULL;
	        m_pRight = NULL;
	};
	~SBinaryNode() {};
};

template<typename T>
class CBinaryTree{
	typedef void (*mpAction)(SBinaryNode<T>* pNode);
private:
	// members;
    SBinaryNode<T>* m_pRoot;
	int m_nSize;
	// private methods;
	void _mPreOrder( mpAction action, SBinaryNode<T>* pNode );
	void _mInOrder( mpAction action, SBinaryNode<T>* pNode );
	void _mPostOrder( mpAction action, SBinaryNode<T>* pNode );
	void _mLevelOrder( mpAction action, SBinaryNode<T>* pNode );
	// output the data;
    static void _mVisit(SBinaryNode<T>* pNode){
		cout << pNode-> m_nData << '\t';
	}
	// free the node;
    static void _mFree(SBinaryNode<T>* pNode){
		delete pNode;
	}
	// figure out the height;
	size_t _mHeight(SBinaryNode<T>* pNode){
		if(!pNode)
			return 0;
        size_t hl = _mHeight( pNode->m_pLeft);  
        size_t hr = _mHeight( pNode->m_pRight);  
		if(hl > hr)
			return hl + 1 ;
		else
			return hr + 1;
	}
    
public:
	// constructors;
	CBinaryTree();
	~CBinaryTree(){
		_mPostOrder(_mFree, m_pRoot);
		m_pRoot = NULL;
	};
	// methods;
	void mMakeTree(const T& elem, CBinaryTree<T>& leftTree, CBinaryTree<T>& rightTree);
	void mBreakTree(T& elem, CBinaryTree<T>& leftTree, CBinaryTree<T>& rightTree);
	// traverse method;
	void mPreOrder();
	void mInOrder();
	void mPostOrder();
	void mLevelOrder();
    bool mRoot(T& x) const;
	bool mIsEmpty() const {return (m_pRoot) ? true : false;}
	size_t mHeight();
};


template<typename T>
CBinaryTree<T>::CBinaryTree():
	m_pRoot(NULL),m_nSize(0) {}

template<typename T>
void CBinaryTree<T>::mMakeTree(const T& elem, CBinaryTree<T>& left, CBinaryTree<T>& right){
	// 
    m_pRoot = new SBinaryNode<T>(elem);
    m_pRoot -> m_pLeft = left.m_pRoot;
	m_pRoot -> m_pRight = right.m_pRoot;
	// protect the left.m_pRoot and right.m_pRoot;
    left.m_pRoot = right.m_pRoot = NULL;
}

template<typename T>
void CBinaryTree<T>::mBreakTree(T& elem, CBinaryTree<T>& leftTree,CBinaryTree<T>& rightTree){
	assert(m_pRoot != NULL);
	// decompose the tree;
	elem = m_pRoot -> m_nData;
    leftTree.m_pRoot = m_pRoot-> m_pLeft;
	rightTree.m_pRoot = m_pRoot -> m_pRight;

	delete root;
}

template<typename T>
bool CBinaryTree<T>::mRoot(T& elem) const{
	if(m_pRoot){
		elem = m_pRoot -> m_nData;
		return true;
	}
	return false;
}

template<typename T>
void CBinaryTree<T>::_mPreOrder(mpAction action, SBinaryNode<T>* pNode){
	if(pNode){
	    action(pNode);	
		_mPreOrder(action, pNode->m_pLeft);
		_mPreOrder(action, pNode->m_pRight);
	}
}

template<typename T>
void CBinaryTree<T>::_mInOrder(mpAction action, SBinaryNode<T>* pNode){
	if(pNode){
		_mInOrder(action, pNode->m_pLeft);
	    action(pNode);	
		_mInOrder(action, pNode->m_pRight);
	}
}

template<typename T>
void CBinaryTree<T>::_mPostOrder(mpAction action, SBinaryNode<T>* pNode){
	if(pNode){
		_mPostOrder(action, pNode->m_pLeft);
		_mPostOrder(action, pNode->m_pRight);
	    action(pNode);	
	}
}

template<typename T>
void CBinaryTree<T>::_mLevelOrder(mpAction action, SBinaryNode<T>* pNode ){
	queue<SBinaryNode<T>*> queueTmp;
	SBinaryNode<T>* pTmpNode = pNode;
    queueTmp.push(pTmpNode);
	while(pTmpNode){
		action(pTmpNode);
		if(pTmpNode -> m_pLeft)
			queueTmp.push(pTmpNode -> m_pLeft);
		if(pTmpNode -> m_pRight) 
		    queueTmp.push(pTmpNode -> m_pRight);
		queueTmp.pop();
		if(queueTmp.empty())
			break;
		pTmpNode = queueTmp.front();
	}
}

template<typename T>
void CBinaryTree<T>::mPreOrder(){
	_mPreOrder(&_mVisit,m_pRoot);
}

template<typename T>
void CBinaryTree<T>::mInOrder(){
	_mInOrder(&_mVisit,m_pRoot);
}

template<typename T>
void CBinaryTree<T>::mPostOrder(){
	_mPostOrder(&_mVisit,m_pRoot);
}

template<typename T>
void CBinaryTree<T>::mLevelOrder(){
    _mLevelOrder(&_mVisit,m_pRoot);
}

template<typename T>
size_t CBinaryTree<T>::mHeight() {
    return _mHeight(m_pRoot);
}
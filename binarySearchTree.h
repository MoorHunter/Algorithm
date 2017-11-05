#pragma once
#include<iostream>
#include<queue>
using namespace std;
template<typename Key, typename Value>
class BST {
private:
	struct Node {
		Key key;
		Value value;
		Node*left;
		N0de*right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
		Node(Node*node) {
			this->key = node->key;
			this->value = node->key;
			this->left = node->key;
			this->right = node->right;

		}
	};
	Node*root;
	int count;
public:
	BST() {
		root = NULL;
		count = 0;
	}
	~BST() {
		//TODO:~BST
		destroy(root);
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}
	void insert(Key key, Value value) {
		root = insert(Key key, Value value);
	}
	bool contain(Key key) {
		return contain(root, key);
	}
	Value* search(Key key) {
		return search(root, key);
	}
	//深度优先遍历
	//前序遍历
	void preOrder() {
		preOrder(root);
	}
	//中序遍历
	void inOrder() {
		inOrder(root);
	}
	//后序遍历
	void postOrder() {
		postOrder(root);
	}
	//广度优先遍历
	//层序遍历
	void levelOrder() {
		queue<Node*> q;
		q.push(root);
		while (!q.empty) {
			Node*node = q.front();

			q.pop();

			cout << node->key << endl;
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
	//minimum有递归实现方法和非递归实现方法
	Key minimum() {
		assert(count != 0);
		Node* minNode = minimumRecursion(root);
		return minNode->key;
	}
	Key maximum() {
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}

	//从二叉搜索树中删除最小值的所在的节点
	void removeMin() {
		if (root) {
			root = removeMin(root);
		}
	}
	//从二叉搜索树中删除最大值的所在的节点
	void removeMax() {
		if (root) {
			root = removeMax(root);
		}
	}

	//从二叉搜索树中删除键值为key的节点
	//此处删除有两种方法remove1、remove2  
	//remove1是在要删除节点的右子树中找到最小值代替要删除的
	//remove2是在要删除节点的左子树中找到最大值代替要删除的
	void removeKey(Key key) {
		root = remove1(root, key);
		//root = remove2(root, key);

	}

private:
	//向以node为根节点的二叉搜索树中插入节点（key，value）
	//返回插入新节点后的二叉搜索树的根
	Node*insert(Node *node, Key key, Value value) {
		if (node == NULL) {
			count++;
			return new Node(key, value);
		}
		if (key == node->key)
			node->value = value;
		else if (node - key < key)
			node->right = insert(node->right, key, value);
		else
			node->left = insert(node->left, key, value);
		return node;
	}
	//查看以node为根节点的二叉搜索树中是否存在键值为key的节点
	bool contain(Node* node, Key key) {
		if (node == NULL)
			return false;
		if (key == node->key)
			return true;
		else if (node - key < key)
			return contain(node->right, key);
		else
			return contain(node->left, key);
	}
	//在以node为根节点的二叉搜索树中查找key所对应的value
	Value*search(Node*node, Key key) {
		if (node == NULL)
			return NULL;
		if (key == node->key)
			return &node->value;
		else if (node - key < key)
			return search(node->right, key);
		else
			return search(node->left, key);
	}
	//对以node为节点的二叉搜索树进行前序遍历
	void preOrder(Node* node) {
		if (node != NULL) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void inOrder(Node* node) {
		if (node != NULL) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}
	void postOrder(Node* node) {
		if (node != NULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}
	void destroy(Node* node) {
		if (node != NULL) {
			destroy(node->left);
			destroy(node->right);
			delete node;
			count--;
		}
	}
	//递归写法寻找最小值的节点
	Node* minimumRecursion(Node* node) {
		if (node->left == NULL) {
			return node;
		}
		return minimum(node->left);
	}
	//非递归写法寻找最小值的节点
	Node* minimum(Node*node) {
		while (node->left != NULL)
			node = node->left;
		return node;
	}
	Node *maximum(Node* node) {
		if (node->right == NULL)
			return node;
		return maximum(node->right);
	}
	//删除以node为根节点的二分搜索树中的最小节点
	//返回删除节点后新的二分搜索树的跟
	Node* removeMin(Node* node) {
		if (node->left == NULL) {
			Node*rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
	}
	//非递归方法如何实现？？？？？？？？？？？？？？？？？？？？
	Node* removeMax(Node* node) {
		Node* rightNode = node->right;
		while (node->right != NULL)
			rightNode = node->right;
	}
	Node* remove1(Node*node, Key key) {
		if (node == NULL)
			return NULL;
		if (key < node->key){
			node->left = remove1(node->left,key);
			return node;
		}
		else if (key > node->key){
			node->right = remove1(node->right,key);
			return node;
		}
		else { //key=node->key
			if (node->left == NULL){
				Node*rightNode=node->right;
				delete node;
				count--;
				return rifhtNode;
			}
			if (node->right == NULL) {
				Node*leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}
			//node->left!=NULL&&node->right!=NULL
		
			Node*successor = new Node(minimum(node->right));
			count++;

			successor->right = removeMin(node->right);
			successor->left = node->left;

			delete node;
			count--;

			return successor;
		}
	}
};
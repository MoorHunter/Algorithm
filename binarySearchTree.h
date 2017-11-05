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
	//������ȱ���
	//ǰ�����
	void preOrder() {
		preOrder(root);
	}
	//�������
	void inOrder() {
		inOrder(root);
	}
	//�������
	void postOrder() {
		postOrder(root);
	}
	//������ȱ���
	//�������
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
	//minimum�еݹ�ʵ�ַ����ͷǵݹ�ʵ�ַ���
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

	//�Ӷ�����������ɾ����Сֵ�����ڵĽڵ�
	void removeMin() {
		if (root) {
			root = removeMin(root);
		}
	}
	//�Ӷ�����������ɾ�����ֵ�����ڵĽڵ�
	void removeMax() {
		if (root) {
			root = removeMax(root);
		}
	}

	//�Ӷ�����������ɾ����ֵΪkey�Ľڵ�
	//�˴�ɾ�������ַ���remove1��remove2  
	//remove1����Ҫɾ���ڵ�����������ҵ���Сֵ����Ҫɾ����
	//remove2����Ҫɾ���ڵ�����������ҵ����ֵ����Ҫɾ����
	void removeKey(Key key) {
		root = remove1(root, key);
		//root = remove2(root, key);

	}

private:
	//����nodeΪ���ڵ�Ķ����������в���ڵ㣨key��value��
	//���ز����½ڵ��Ķ����������ĸ�
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
	//�鿴��nodeΪ���ڵ�Ķ������������Ƿ���ڼ�ֵΪkey�Ľڵ�
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
	//����nodeΪ���ڵ�Ķ����������в���key����Ӧ��value
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
	//����nodeΪ�ڵ�Ķ�������������ǰ�����
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
	//�ݹ�д��Ѱ����Сֵ�Ľڵ�
	Node* minimumRecursion(Node* node) {
		if (node->left == NULL) {
			return node;
		}
		return minimum(node->left);
	}
	//�ǵݹ�д��Ѱ����Сֵ�Ľڵ�
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
	//ɾ����nodeΪ���ڵ�Ķ����������е���С�ڵ�
	//����ɾ���ڵ���µĶ����������ĸ�
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
	//�ǵݹ鷽�����ʵ�֣���������������������������������������
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
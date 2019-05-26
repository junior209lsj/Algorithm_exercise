#include <iostream>

#include <stdio.h>

using namespace std;

struct Node
{
	char data;
	Node *leftChild;
	Node *rightChild;
};

struct NodeInfo
{
	char me;
	char left;
	char right;
};

class Tree
{
public:
	Node *root;
	Node *iterator;
	int num_of_node;
	char tmpP, tmpL, tmpR;
	NodeInfo *infos;
	
	void GetNum()
	{
		cin >> num_of_node;
	}

	void GetNodes()
	{
		infos = new NodeInfo[num_of_node];
		int i = 0;
		while(i < num_of_node) {
			cin >> tmpP >> tmpL >> tmpR;
			infos[i].me = tmpP;
			infos[i].left = tmpL;
			infos[i].right = tmpR;
			i++;
		}
	}

	Node* FindNode(Node *Tree, char key)
	{
		//Base Case
		if(Tree->data == key) {
			return Tree;
		}
		else if(Tree->leftChild == NULL && Tree->rightChild == NULL) {
			return NULL;
		}
		//recursive case
		else if(Tree->leftChild != NULL && Tree->rightChild == NULL) {
			return FindNode(Tree->leftChild, key);
		}
		else if(Tree->leftChild == NULL && Tree->rightChild != NULL) {
			return FindNode(Tree->rightChild, key);
		}
		else {
			Node *tmp = FindNode(Tree->leftChild, key);
			if(tmp == NULL) {
				return FindNode(Tree->rightChild, key);
			}
			else {
				return tmp;
			}
		}
	}

	Node* CreateNode(char key)
	{
		Node *temp = new Node;
		temp->data = key;
		temp->leftChild = NULL;
		temp->rightChild = NULL;
		return temp;
	}

	void CreateTree()
	{
		GetNum();
		GetNodes();
		int i = 0;
		while(i < num_of_node) {
			if(i == 0) {
				root = CreateNode(infos[i].me);
				if(infos[i].left != '.') {
					root->leftChild = CreateNode(infos[i].left);
				}
				if(infos[i].right != '.') {
					root->rightChild = CreateNode(infos[i].right);
				}
			}
			else {
				iterator = FindNode(root, infos[i].me);
				if(infos[i].left != '.') {
					iterator->leftChild = CreateNode(infos[i].left);
				}
				if(infos[i].right != '.') {
					iterator->rightChild = CreateNode(infos[i].right);
				}
			}
			i++;
		} 
	}

	void PreorderSearch(Node* Tree) {
		printf("%c", Tree->data);
		if(Tree->leftChild != NULL) {
			PreorderSearch(Tree->leftChild);
		}
		if(Tree->rightChild != NULL) {
			PreorderSearch(Tree->rightChild);
		}
	}

	void InorderSearch(Node* Tree) {
		if(Tree->leftChild != NULL) {
			InorderSearch(Tree->leftChild);
		}
		printf("%c", Tree->data);
		if(Tree->rightChild != NULL) {
			InorderSearch(Tree->rightChild);
		}
	}	

	void PostorderSearch(Node * Tree) {
		if(Tree->leftChild != NULL) {
			PostorderSearch(Tree->leftChild);
		}
		if(Tree->rightChild != NULL) {
			PostorderSearch(Tree->rightChild);
		}
		printf("%c", Tree->data);
	}
	
	
};

int main()
{
	Tree T;
	T.CreateTree();
	T.PreorderSearch(T.root);
	cout << endl;
	T.InorderSearch(T.root);
	cout << endl;
	T.PostorderSearch(T.root);
	cout << endl;

	return 0;
}
#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node *leftChild;
	Node *rightChild;
};

class Tree
{
	Node *root;
	int num_of_node;
	char tmpP, tmpL, tmpR;
	
	void GetNum()
	{
		cin >> num_of_node;
	}
	
	Node* CreateNode(char x)
	{
		try {
			Node *temp = new Node;
			if(temp == nullptr) {
				throw temp
			}
		}
		catch(Node* exeption) {
			cout << "메모리 할당 오류" << endl;
		}
		return temp;
	}
	
	Node* CreateNode(char x, Node* pos)
	{
	}
	
	void CreateTree()
	{
		cin >> tmpP >> tmpL >> tmpR;
		
		//Base case: leaf
		if(tmpL == '.' && tmpR == '.') {
			return;
		}
		
		//root
		if(tmpP == 'A') {
			root = CreateNode(tmpP);
			if(tmpL != '.') {
				CreateNode()
			}
		}
		
		
		
		
	}
};

int main()
{
}
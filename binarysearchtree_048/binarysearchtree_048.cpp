#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//Constructor for the node class
	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;

	BinaryTree() {
		ROOT = NULL; //initializing root to null
	}

	void insert(string element) { //insert a node in the binary search tree
		Node* newNode = new Node(element, NULL, NULL); //Allocate memory for the new node
		newNode->info = element; //Assign value to the data field of the new node
		newNode->leftchild = NULL; // Buat left child dari new Node ke NULL
		newNode->rightchild = NULL; // Buat right child dari new Node ke NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); // Menemukan node yang akan menjadi parent dari Node yang disisipkan

		if (parent == NULL) //Jika parentnya adalah NULL (Tree is empty)
		{
			ROOT = newNode; // Tandai new node sebagai ROOT 
			return; // Exit
		}

		if (element < parent->info) //Jika data field new Node lebih kecil dari parent
		{
			parent->leftchild = newNode; // Membuat left child dari parent point ke new Node
		}
		else if (element > parent->info) //Jika data field new Node lebih besar dari parent
		{
			parent->rightchild = newNode; // Membuat right child dari parent  ke new Node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode) {
		//Fungsi ini mencari Node saat ini dari Node yang ditenukan serta Node saat ini dari parent
		currentNode = ROOT; 
		parent = NULL; 
		while ((currentNode != NULL) && (currentNode->info != element)) 
		{
			parent = currentNode; 
			if (element < currentNode->info) 
				currentNode = currentNode->leftchild; 
			else
				currentNode = currentNode->rightchild; 
		}
	}

	void inorder(Node* ptr) {
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr) {

	}
};
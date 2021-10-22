#include "BST.h"
#include <iostream>
#include <vector>

using namespace::std;

bool BST::insert(char mChar, int val)
{
	return pinsert(root, val, mChar);
}


bool BST::pinsert(Node*& node, int val, char mChar)
// bool BST::insert(Node*& node, int val)
{
	if (node == nullptr)
	{
		node = new Node(mChar, val);
		// node = new Node(val);
		return true;
	}
	if (val < node->bstVal)
	{
		return pinsert(node->right, val, mChar);
	}
	if (val > node->bstVal)
	{
		return pinsert(node->left, val, mChar);
	}
	return false;
}

bool BST::remove(char mChar, int val)
{
	return premove(root, val, mChar);
}

bool BST::premove(Node*& node, int val, char mChar)
{
	if (node == nullptr)
	{
		return false;
	}
	if (val < node->bstVal)
	{
		return premove(root, val, node->left->morseChar);
	}
	if (val > node->bstVal)
	{
		return premove(root, val, node->right->morseChar);
	}

	int deg = node->degree();

	if (deg == 0)
	{
		delete node;
		node = nullptr;
	}
	else if (deg == 1)
	{
		Node* tmp = node;

		if (node->left != nullptr)
		{
			node = node->left;
		}
		else 
		{
			node = node->right;
		}

		delete tmp;
	}
	else
	{
		Node* tmp = node->left;
		
		while (tmp->right != nullptr)
		{
			tmp = tmp->right;
		}

		node->bstVal = tmp->bstVal;
		premove(root, node->left->morseChar, tmp->bstVal);
	}

	return true;
}

void BST::postOrder()
{
	Node *tmp = root;

	ppostOrder(tmp);
}

void BST::ppostOrder(Node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    ppostOrder(node->left);
 
    // then recur on right subtree
    ppostOrder(node->right);
 
    // now deal with the node
	cout << "<" << node->morseChar << ", " << node->bstVal << "> ";
}

void BST::inOrder()
{
	Node *tmp = root;

	pinOrder(tmp);
}

void BST::pinOrder(Node* node) // This order is according to Devin Neal's example output
{
	if (node == NULL) {
		return;
	}
 
    /* first recur on left child */
    pinOrder(node->right);
 
    /* then print the data of node */
	cout << "<" << node->morseChar << ", " << node->bstVal << "> ";
 
    /* now recur on right child */
    pinOrder(node->left);
}

void BST::preOrder()
{
	Node *tmp = root;

	ppreOrder(tmp);
}

void BST::ppreOrder(Node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
	cout << "<" << node->morseChar << ", " << node->bstVal << "> ";
 
    /* then recur on left sutree */
    ppreOrder(node->left);
 
    /* now recur on right subtree */
    ppreOrder(node->right);
}

void BST::constructTree(int data)
{
	Morse mtree;
	vector<char> tree;
	for (int i = 0; i < 63; i++) {
		tree.push_back(mtree.morseTree[i]);
	}
	return pconstructTree(root, data, tree);
}

void BST::pconstructTree(Node*& node, int depth, vector<char> mtree) // Used vector to make it easier for me.
{
	
	int arrCount = 0;

	for (int rowCount = 0; rowCount <= depth; rowCount++)
	{
		int rowElementCount = pow(2, rowCount);

		int rowElement = pow(2, (depth - rowCount));

		int rowElementCounter = pow(2, (depth - rowCount + 1));

		for (int j = 0; j < rowElementCount; j++, rowElement += rowElementCounter)
		{
			insert(mtree[arrCount], rowElement);
			arrCount++;
		}
	}
	
}

void BST::convertString(string strArg1) // uses character array and string arrays to find a letter inside the user input string and compare it to its morse code equality
{
	char text[36] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	 '1','2','3','4','5','6','7','8', '9','0' };

	string morse[36] = { ".-","-...","-.-.","-..",".","..-","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",
	".----","..---","...--","....-",".....","-....","--....","---..","----.","-----" };

	for (int i = 0; i < strArg1.length(); i++)
	{
		for (int j = 0; j < 36; j++)
		{
			if (strArg1[i] == text[j]) {
				cout << morse[j] << endl;
				break;
			}
		}
	}
}

void BST::clear()
{
	Node* tmp = root;

	pclear(tmp);
}

// Utilized code from previous doubly linked list to solve this
void BST::pclear(Node* node)
{
	{
		Node* tmp = root;

		while (tmp != nullptr)
		{
			root = root->right;
			delete tmp;
			tmp = root;
		}

		root = nullptr;
	}
}


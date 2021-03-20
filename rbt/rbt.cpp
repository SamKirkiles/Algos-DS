#include <iostream>
#include "rbt.h"

using namespace std;

// Takes a tree and the node to left rotate
void leftRotate (RBTNode * tree, RBTNode* rotate){
	
	RBTNode * x = rotate;
	RBTNode * y = (*x).right;	
	
	if (y == NULL){
		cout << "Error! tried to rotate a leaf node! \n";
		return;
	}
	(*x).right = (*y).left;	

	if ((*y).left != NULL){
		(*x).right = (*y).left;
	}

	(*y).parent = (*x).parent;
	
	// What happens if (*x).parent == NULL?
	if (x == (*(*x).parent).left){
		(*x).parent->left = y;
	}else{
		(*x).parent->right = y;
	}
	
	(*y).left = x;
	(*x).parent = y;
	return;
}

void insert_node(RBTNode* tree, int insert){
	
	//Insert into a red/black tree	

	if (tree == NULL) {

		RBTNode* outTree = (RBTNode*) malloc(sizeof(RBTNode)); // Create an RBTNode 
		outTree->value = insert;
		outTree->left = NULL;
		outTree->right = NULL;
		outTree->parent = NULL;
		outTree-> c = BLACK;
		
		*tree = *outTree;
	}	
	
	if ((*tree).value <= insert) { // Then we insert on the right side 
	
		if ((*tree).right == NULL) { // There is no node on the right so we can just add the new node there 

			RBTNode* insertNode = (RBTNode*) malloc(sizeof(RBTNode)); // Create an RBTNode 
			insertNode->value = insert;
			insertNode->left = NULL;
			insertNode->right = NULL;
			insertNode->parent = tree;
			insertNode-> c = RED;
		
			tree->right=insertNode;
		} else{
			insert_node((*tree).right, insert);
		}
	}else{
		if ((*tree).left == NULL) { // There is no node on the right so we can just add the new node there 

			RBTNode* insertNode = (RBTNode*) malloc(sizeof(RBTNode)); // Create an RBTNode 
			insertNode->value = insert;
			insertNode->left = NULL;
			insertNode->right = NULL;
			insertNode->parent = tree;
			insertNode-> c = RED;
		
			tree->left=insertNode;
		} else{
			insert_node((*tree).left, insert);
		}
	}

}




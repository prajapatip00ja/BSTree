#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

Node* create_node(int i){
	Node* node = malloc(sizeof(Node));
	node->data = i;
	node->left = NULL;
	node->right = NULL;
	return node;
}


BSTree createBSTree(void){
	BSTree tree;
	tree.root = NULL;
	return tree;
}

int insert(BSTree* tree, int i){
	Node* node = create_node(i);
	if(tree->root==NULL){
		(tree->root = node);
		return 1;
	}
	if(i>tree->root->data){
		if(tree->root->right==NULL)
			tree->root->right = node;
		else{
			tree->root = tree->root->right;
			insert(tree,i);
		}
	}
	else{
		if(tree->root->left==NULL)
			tree->root->left = node;
		else{
			tree->root = tree->root->left; 
			insert(tree,i);
		}
	}	
	return 1;
}



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
	if(i > tree->root->data){
		if(tree->root->right==NULL)
			tree->root->right = node;
		else{
			BSTree* Subtree = malloc(sizeof(BSTree));
			Subtree->root = tree->root->right;
			insert(Subtree,i);
		}
	}
	else{
		if(tree->root->left==NULL)
			tree->root->left = node;
		else{
			BSTree* Subtree = malloc(sizeof(BSTree));
			Subtree->root = tree->root->left;
			insert(Subtree,i);
		}
	}	
	return 1;
}

Node* find(BSTree tree, int element){
	Node* node = tree.root;
	if(tree.root->data==element)
		return node;
	else{
		if(element>tree.root->data){
			(tree.root->right == NULL)?(node=NULL):(tree.root = tree.root->right);
			(node!=NULL) && (node = find(tree,element));
		}
		else{
			(tree.root->left == NULL)?(node=NULL):(tree.root = tree.root->left);
			(node!=NULL) && (node = find(tree,element));	
		}
	}	
	return node;
}



Node* findParent(BSTree tree,Node* node){
	Node* parNode;
	if(tree.root->right == node || tree.root->left == node){
		return tree.root;
	}
	else{
		if(node->data > tree.root->data){
			(tree.root->right == NULL)?(parNode=NULL):(tree.root = tree.root->right);
			(parNode!=NULL) && (parNode = findParent(tree,node));
		}
		else{
			(tree.root->left == NULL)?(parNode=NULL):(tree.root = tree.root->left);
			(parNode!=NULL) && (parNode = findParent(tree,node));	
		}
	}
	return parNode;
};






Node* delete(BSTree* tree, int data){
	Node *node,*parNode;
	node = find(*tree,data);
	parNode = findParent(*tree,node);
	if(node->left==NULL && node->right==NULL){
		if(parNode==NULL)
			return node;
		(node == parNode->left) && (parNode->left=NULL) ;
		(node == parNode->right) && (parNode->right = NULL) ;
		return node;		
	}
	else if(node->left!=NULL || node->right!=NULL){
		if(node == parNode->left){
			node->left != NULL && (parNode->left=node->left);
			node->right!=NULL && (parNode->left=node->right);
		}
		else{
			node->left != NULL && (parNode->right=node->left);
			node->right!=NULL && (parNode->right=node->right);
		} 
		return node;	
	};

}

int printElement(int i){
	printf("%d\n",i);
	return 1;
}

void traverse(BSTree tree,Function fn_ptr){
	Node* root = tree.root;
	if(tree.root==NULL)
		return;
	tree.root = tree.root->left; 
	traverse(tree,fn_ptr);
	(*fn_ptr)(root->data);
	tree.root = root->right;
	traverse(tree,fn_ptr);
}






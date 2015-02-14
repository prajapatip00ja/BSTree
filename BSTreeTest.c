#include <stdio.h>
#include "BSTree.h"
#include "expr_assert.h"
#include <string.h>
//#include <assert.h>

void test_createTree_has_created_the_tree(){
	BSTree tree = createBSTree();
	assertEqual((int)tree.root,0);
}

void test_insert_method_insert_a_node_in_tree_if_tree_is_empty(){
	int i =5;
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,i),1);
	assertEqual((int)tree.root->data,5);
}

void test_insert_method_insert_a_node_in_tree_if_tree_is_not_empty(){
	int i = 5,j = 8, k = 10, l = 4 ;
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,i),1);
	assertEqual((int)tree.root->data,5);
	assertEqual(insert(&tree,j),1);
	assertEqual((int)tree.root->right->data,8);
	assertEqual(insert(&tree,k),1);
	assertEqual((int)tree.root->right->right->data,10); 
	assertEqual(insert(&tree,l),1);
	assertEqual((int)tree.root->left->data,4); 
}

void test_find_method_find_the_node_from_tree(){
	int i = 5,j = 8, k = 2, l = 4 ,item1 = 5, item2 = 8, item3 = 2,item4 = 1;
	Node* node ;
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,i),1);
	assertEqual(insert(&tree,j),1);
	assertEqual(insert(&tree,k),1);
	assertEqual(insert(&tree,l),1);
	node = find(tree,item1); 
	assertEqual(node->data,5);
	node = find(tree,item2); 
	assertEqual(node->data,8);
	node = find(tree,item3);
	assertEqual(node->data,2); 
	node = find(tree,4);
	assertEqual(node->data,4); 
}

void test_find_method_find_the_ref_of_node_from_tree(){
	int i = 5,j = 8, k = 2, l = 4 ,item1 = 5, item2 = 8, item3 = 2,item4 = 4;
	Node *node1,*node2,*node3,*node4;
	Node* parNode;
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,i),1);
	assertEqual(insert(&tree,j),1);
	assertEqual(insert(&tree,k),1);
	assertEqual(insert(&tree,l),1);
	 
	node2 = find(tree,8); 
	assertEqual(node2->data,8);
	node3 = find(tree,2);
	parNode = findParent(tree,node3);
	assert(tree.root==parNode);		 
	node4 = find(tree,4);
	parNode = findParent(tree,node4);
	assert(tree.root->left==parNode);
	node1 = find(tree,5);
	parNode = findParent(tree,node1);
	assert(parNode==NULL);
}

void test_delete_method_will_delete_the_leaf_node(){
	int i = 5,j = 8, k = 2, l = 4 ,item1 = 5, item2 = 8, item3 = 2,item4 = 4;
	Node *node1,*node2,*node3,*node4;
	Node* parNode;
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,i),1);
	assertEqual(insert(&tree,j),1);
	assertEqual(insert(&tree,k),1);
	assertEqual(insert(&tree,l),1);
	node1 = delete(&tree,8);
	assertEqual(node1->data,8);
	node2 = delete(&tree,2);
	//printf("%d",tree.root->left->data);
	assertEqual(tree.root->left->data,4);
	//assert(tree.root->left==node1);
}



void test_travarse_method_will_traverse_through_tree_in_inorder_method(){
	int i = 5,j = 8, k = 2, l = 4, m=3 ,item1 = 5, item2 = 8, item3 = 2,item4 = 4;
	Node *node1,*node2,*node3,*node4;
	Node* parNode;
	BSTree tree = createBSTree();
	Function fun_ptr;
	assertEqual(insert(&tree,i),1);
	assertEqual(insert(&tree,j),1);
	assertEqual(insert(&tree,k),1);
	assertEqual(insert(&tree,l),1);
	assertEqual(insert(&tree,m),1);
	fun_ptr = &(printElement);
	traverse(tree,fun_ptr);
}


#include <stdio.h>
#include "BSTree.h"
#include "expr_assert.h"

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
	int i = 5,j = 8, k = 2, l = 4 ;
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,i),1);
	assertEqual((int)tree.root->data,5);
	assertEqual(insert(&tree,j),1);
	assertEqual((int)tree.root->right->data,8);
	assertEqual(insert(&tree,k),1);
	assertEqual((int)tree.root->left->data,2); 
	assertEqual(insert(&tree,l),1);
	assertEqual((int)tree.root->right->data,4); 
}

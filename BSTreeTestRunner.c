#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_createTree_has_created_the_tree,test_insert_method_insert_a_node_in_tree_if_tree_is_empty,test_insert_method_insert_a_node_in_tree_if_tree_is_not_empty,test_find_method_find_the_node_from_tree,test_find_method_find_the_ref_of_node_from_tree,test_delete_method_will_delete_the_leaf_node,test_travarse_method_will_traverse_through_tree_in_inorder_method;
Test test[] = {"test_createTree_has_created_the_tree",test_createTree_has_created_the_tree,"test_insert_method_insert_a_node_in_tree_if_tree_is_empty",test_insert_method_insert_a_node_in_tree_if_tree_is_empty,"test_insert_method_insert_a_node_in_tree_if_tree_is_not_empty",test_insert_method_insert_a_node_in_tree_if_tree_is_not_empty,"test_find_method_find_the_node_from_tree",test_find_method_find_the_node_from_tree,"test_find_method_find_the_ref_of_node_from_tree",test_find_method_find_the_ref_of_node_from_tree,"test_delete_method_will_delete_the_leaf_node",test_delete_method_will_delete_the_leaf_node,"test_travarse_method_will_traverse_through_tree_in_inorder_method",test_travarse_method_will_traverse_through_tree_in_inorder_method};
char testFileName[] = {"BSTreeTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}
typedef struct node Node;
typedef struct tree BSTree;
typedef struct parent Parent;
typedef int (*Function)(int);

struct node{
	int data;
	Node* left;
	Node* right;
};



struct tree{
	Node* root;
};

BSTree createBSTree(void);
int insert(BSTree *, int);
Node* find(BSTree, int);
void traverse(BSTree,Function);
Node* delete(BSTree*, int);
Node* findParent(BSTree,Node*);
Node* create_node(int i);
int printElement(int i);
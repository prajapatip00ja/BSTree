typedef struct node Node;
typedef struct tree BSTree;

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
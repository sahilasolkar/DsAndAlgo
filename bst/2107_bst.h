
/*
AUTHOR : SAHIL.A
PROGRAM: queue USING LINKED LIST. LIB HEADER FILE
DATE CREATED: 22th SEPT 2021
DATE MODIFIED: 7th NOV 2021
*/
// DS DEVELOPER


#ifndef _bst_H
#define _bst_H
//data
typedef int eleType;
struct tree_head
{
    struct tree_node *root;
    eleType count;
};

typedef struct tree_head bst_tree;

struct tree_node
{
    eleType data;
    struct tree_node *right;
    struct tree_node *left;
};


typedef struct tree_node node;
//opertations

bool isEmpty(bst_tree *tree);

bst_tree * BST_create();

bool BST_insert(bst_tree * tree, eleType data);
node * _insert(node * root, node * newptr);

void BST_traversal(bst_tree * tree);
void _traverse(node * root);

node * _delete(node * root, eleType dltkey, bool *success);
bool BST_Delete (bst_tree * tree, eleType dltkey);

//void _destroy(node * root, bst_tree *tree);
void bst_destroy(bst_tree * tree);

node *searchtree(node *root,eleType data);

#endif

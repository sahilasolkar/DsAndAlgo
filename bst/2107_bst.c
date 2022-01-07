
/*AUTHOR : SAHIL.A
PROGRAM: queue USING LINKED LIST. LIB IMPLEMENTATION
DATE CREATED: 22th SEPT 2021
DATE MODIFIED: 7th NOV 2021
*/
// DS DEVELOPER


#include<stdio.h>
#include<stdbool.h>
#include"2107_bst.h"
#include<stdlib.h>

bool isEmpty(bst_tree *tree) 
{
    if(tree->count==0)
    {
        return true;
    }
    return false;
}

bst_tree * BST_create()
{
  bst_tree * newtree = (bst_tree*)malloc(sizeof(bst_tree));
  if (newtree)
  {
    newtree->root = NULL;
    newtree->count=0;
  }
  return newtree;
}

//inserts a new element into the tree
bool BST_insert(bst_tree * tree, eleType data)
{
  node * newptr = (node *)malloc(sizeof (node));
  if (!newptr)
  {
    return false;
  }
  else
  {
    newptr->data = data;
    newptr->right = NULL;
    newptr->left = NULL;
  }

  if (tree->count==0)
  {
    tree->root=newptr;
  }
  else
  {
    _insert(tree->root, newptr);
  }

  (tree->count)++;
  return true;
}

//recursive _insert function

node * _insert(node * root, node * newptr)
{
  if (!root)
  {
    return newptr;

  }

  if (newptr->data < root->data)
  {
    root->left=_insert(root->left, newptr);
  }
  else 
  {
    root->right=_insert(root->right, newptr);
  }

  return root;

}

//inorder traversal
void BST_traversal(bst_tree * tree)
{
  _traverse(tree->root);
}

//performs inorder traversal
void _traverse(node * root)
{
  if (root)
  {
    _traverse(root->left);
    printf("  %d  ", root->data);
    _traverse(root->right);
  }
}

//recursively searches and deletes the element
node * _delete(node * root, eleType dltkey, bool *success)
{

  if(root==NULL)
  {

    success = false;
    return NULL;

  }
  if(dltkey<root->data)
  {
    root->left=_delete(root->left, dltkey, success);

  }
  else if (dltkey>root->data)
  {

    root->right=_delete(root->right, dltkey, success);

  }

  else  //dlt key found 
  {

    if(root->right && root->left)  //2 children 
    {
      //a. find the inorder predeccessor for the node to be deleted

      node * inorder_pre= root->left;

      while(inorder_pre->right)
      {
        inorder_pre = inorder_pre->right;
      }

      //b. copy the data of the inorder_pre in the node to be deleted

      root->data = inorder_pre->data;

      //c. delete the inorder_pre 

      root->left= _delete(root->left, inorder_pre->data, success);


    }

    else   //0 or 1 children
    {
      node * temp = root;
      if (root->left==NULL)
      {

        root=root->right;

      }
      else if (root->right==NULL)
      {

        root=root->left;

      }
      free(temp);
      *success=true;
    }

  }

  return root;

}

//deletes the element
bool BST_Delete (bst_tree * tree, eleType dltkey)
{
  bool success;
  node * newroot;
  newroot = _delete(tree->root, dltkey, &success);
  if(success)
  {

    tree->root=newroot;
    (tree->count)--;
    if (tree->count==0)
    {
      tree->root=NULL;

    }

  }
  return success;
}

//destroys the tree
void bst_destroy(bst_tree *tree)
{
  while (tree->root!=NULL)
  {
    node *temp=tree->root;
    if(tree->root->left)
      tree->root=tree->root->left;
    else
      tree->root=tree->root->right;
    free(temp);
    tree->count--;
  }  
}


//traverses the entire tree and searched for the element recursively
node *searchtree(node *root,eleType data)
{
  if(root==NULL)
  {
    return NULL;
  }
  else if(data < root->data)
  {
    return searchtree(root->left,data);
  }
  else if(data > root->data )
  {
    return searchtree(root->right,data);
  }
  else if(data == root->data)
  {
    printf("\n your searched element is - \n ");
    printf("\n %d", data);
    return root;
  }
  else
  return root;
}

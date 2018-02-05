// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices 
// reachable from s.
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
struct bstNode {
  int data;
  bstNode* left;
  bstNode* right;
  
  bstNode(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};
 
/* A function that constructs Balanced Binary Search Tree from a sorted array */
bstNode *sortedArrayToBST(vector<int> vec, int start, int end)
{
  /* Base Case */
  if (start > end) return NULL;

  /* Get the middle element and make it root */
  int mid = (start + end)/2;
  bstNode *root = new bstNode(vec[mid]);
 
  /* Recursively construct the left subtree and make it
     left child of root */
  root->left =  sortedArrayToBST(vec, start, mid-1);
 
  /* Recursively construct the right subtree and make it
     right child of root */
  root->right = sortedArrayToBST(vec, mid+1, end);
  
  return root;
};
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct bstNode* node)
{
  if (node == NULL) return;
    
  cout << node->data << " ";
  preOrder(node->left);
  preOrder(node->right);
}
 
/* Driver program to test above functions */
int main()
{
  vector<int> vec = {3, 8, 12, 13, 18, 21, 26};
 
  /* Convert List to BST */
  bstNode *root = sortedArrayToBST(vec, 0, vec.size()-1);
  cout << "n PreOrder Traversal of constructed BST ";
  preOrder(root);
  cout << endl;

  return 0;
}
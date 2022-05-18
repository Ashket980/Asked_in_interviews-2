#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to print all ancestors of a given node in a binary tree.
// The function returns true if the node is found in the subtree rooted at the
// given root node.
bool printAncestors(Node* root, Node* node)
{
    // base case
    if (root == nullptr) {
        return false;
    }
 
    // return true if a given node is found
    if (root == node) {
        return true;
    }
 
    // search node in the left subtree
    bool left = printAncestors(root->left, node);
 
    // search node in the right subtree
    bool right = false;
    if (!left) {
        right = printAncestors(root->right, node);
    }
 
    // if the given node is found in either left or right subtree,
    // the current node is an ancestor of a given node
    if (left || right) {
        cout << root->data << " ";
    }
 
    // return true if a node is found
    return left || right;
}
 
int main()
{
    /* Construct the following tree
         1
       /   \
      /     \
     2       3
      \     / \
       4   5   6
          / \
         7   8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    Node* node = root->right->left->left;    // Node 7
    printAncestors(root, node);
 
    return 0;
}

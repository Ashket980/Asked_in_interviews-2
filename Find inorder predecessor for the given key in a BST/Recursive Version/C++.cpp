#include <iostream>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Helper function to find the maximum value node in a given BST
Node* findMaximum(Node* root)
{
    while (root->right) {
        root = root->right;
    }
 
    return root;
}
 
// Recursive function to find inorder predecessor for a given key in the BST
Node* findPredecessor(Node* root, Node* prec, int key)
{
    // base case
    if (root == nullptr) {
        return prec;
    }
 
    // if a node with the desired value is found, the predecessor is the maximum
    // value node in its left subtree (if any)
    if (root->data == key)
    {
        if (root->left != nullptr) {
            return findMaximum(root->left);
        }
    }
 
    // if the given key is less than the root node, recur for the left subtree
    else if (key < root->data) {
        return findPredecessor(root->left, prec, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        // update predecessor to the current node before recursing
        // in the right subtree
        prec = root;
        return findPredecessor(root->right, prec, key);
    }
    return prec;
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    /* Construct the following tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
    */
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // find inorder predecessor for each key
    for (int key: keys)
    {
        Node* prec = findPredecessor(root, nullptr, key);
 
        if (prec != nullptr) {
            cout << "The predecessor of node " << key << " is " << prec->data << endl;
        }
        else {
            cout << "The predecessor doesn't exist for " << key << endl;
        }
    }
 
    return 0;
}

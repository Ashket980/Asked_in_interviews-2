#include <iostream>
#include <climits>
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
 
// Function to perform inorder traversal on the given binary tree and
// check if it is a BST or not. Here, `prev` is the previously processed node
bool isBST(Node* root, Node* &prev)
{
    // base case: empty tree is a BST
    if (root == nullptr) {
        return true;
    }
 
    // check if the left subtree is BST or not
    bool left = isBST(root->left, prev);
 
    // value of the current node should be more than that of the previous node
    if (root->data <= prev->data) {
        return false;
    }
 
    // update the previous node and check if the right subtree is BST or not
    prev = root;
    return left && isBST(root->right, prev);
}
 
// Function to determine whether a given binary tree is a BST
void isBST(Node* node)
{
    // pointer to store previously processed node in the inorder traversal
    Node* prev = new Node(INT_MIN);
 
    // check if nodes are processed in sorted order
    if (isBST(node, prev)) {
        printf("The tree is a BST.");
    }
    else {
        printf("The tree is not a BST!");
    }
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // swap nodes
    swap(root->left, root->right);
    isBST(root);
 
    return 0;
}

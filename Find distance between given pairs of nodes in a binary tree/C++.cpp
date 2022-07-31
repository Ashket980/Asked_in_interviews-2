#include <iostream>
#include <climits>
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
 
// Helper function to check if a given node is present in a binary tree or not
bool isNodePresent(Node* root, Node* node)
{
    // base case
    if (root == nullptr) {
        return false;
    }
 
    // if the node is found, return true
    if (root == node) {
        return true;
    }
 
    // return true if the node is found in the left or right subtree
    return isNodePresent(root->left, node) ||
            isNodePresent(root->right, node);
}
 
// Helper function to find the level of a given node present in a binary tree
int findLevel(Node* root, Node* node, int level)
{
    // base case
    if (root == nullptr) {
        return INT_MIN;
    }
 
    // return level if the node is found
    if (root == node) {
        return level;
    }
 
    // search node in the left subtree
    int left = findLevel(root->left, node, level + 1);
 
    // if the node is found in the left subtree, return the left pointer
    if (left != INT_MIN) {
        return left;
    }
 
    // otherwise, continue the search in the right subtree
    return findLevel(root->right, node, level + 1);
}
 
// Function to find the lowest common ancestor of given nodes `x` and `y`,
// where both `x` and `y` are present in a binary tree.
Node* findLCA(Node* root, Node* x, Node* y)
{
    // base case 1: if the tree is empty
    if (root == nullptr) {
        return nullptr;
    }
 
    // base case 2: if either `x` or `y` is found
    if (root == x || root == y) {
        return root;
    }
 
    // recursively check if `x` or `y` exists in the left subtree
    Node* left = findLCA(root->left, x, y);
 
    // recursively check if `x` or `y` exists in the right subtree
    Node* right = findLCA(root->right, x, y);
 
    // if `x` is found in one subtree and `y` is found in the other subtree,
    // update lca to the current node
    if (left && right) {
        return root;
    }
 
    // if `x` and `y` exist in the left subtree
    if (left) {
        return left;
    }
 
    // if `x` and `y` exist in the right subtree
    if (right) {
        return right;
    }
}
 
// Function to find the distance between node `x` and node `y` in a
// given binary tree rooted at `root` node
int findDistance(Node* root, Node* x, Node* y)
{
    // `lca` stores the lowest common ancestor of `x` and `y`
    Node* lca = nullptr;
 
    // call LCA procedure only if both `x` and `y` are present in the tree
    if (isNodePresent(root, y) && isNodePresent(root, x)) {
        lca = findLCA(root, x, y);
    }
    else {
        return INT_MIN;
    }
 
    // return distance of `x` from lca + distance of `y` from lca
    return findLevel(lca, x, 0) + findLevel(lca, y, 0);
 
    /*
        The above statement is equivalent to the following:
 
        return findLevel(root, x, 0) + findLevel(root, y, 0) -
                2*findLevel(root, lca, 0);
 
        We can avoid calling the `isNodePresent()` function by using
        return values of the `findLevel()` function to check if
        `x` and `y` are present in the tree or not.
    */
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
           /     \
          7       8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->right->right = new Node(8);
 
    // find the distance between node 7 and node 6
    cout << findDistance(root, root->right->left->left, root->right->right);
 
    return 0;
}

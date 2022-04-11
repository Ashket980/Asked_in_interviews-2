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
 
// Helper function
void findDiff(Node* root, int &diff, int level)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // if the current level is odd
    if (level & 1) {
        diff += root->data;
    }
    // if the current level is even
    else {
        diff -= root->data;
    }
 
    // recur for the left and right subtree
    findDiff(root->left, diff, level + 1);
    findDiff(root->right, diff, level + 1);
}
 
// Function to calculate the difference between the sum of all nodes present
// at odd levels and the sum of all nodes present at even level
int findDiff(Node* root)
{
    int diff = 0;
    findDiff(root, diff, 1);
 
    return diff;
}
 
int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         /      /  \
        /      /    \
       4      5      6
             / \
            /   \
           7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    cout << findDiff(root);
 
    return 0;
}

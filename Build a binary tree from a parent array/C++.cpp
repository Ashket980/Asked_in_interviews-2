#include <iostream>
#include <vector>
#include <unordered_map>
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
 
// Function to perform inorder traversal on the tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
// Function to build a binary tree from the given parent array
Node *createTree(vector<int> const &parent)
{
    int n = parent.size();
 
    // create an empty map
    unordered_map<int, Node*> map;
 
    // create `n` new tree nodes, each having a value from 0 to `n-1`,
    // and store them in a map
    for (int i = 0; i < n; i++) {
        map[i] = new Node(i);
    }
 
    // represents the root node of a binary tree
    Node* root = nullptr;
 
    // traverse the parent array and build the tree
    for (int i = 0; i < n; i++)
    {
        // if the parent is -1, set the root to the current node having the
        // value `i` (stored in map[i])
        if (parent[i] == -1) {
            root = map[i];
        }
        else {
            // get the parent for the current node
            Node* ptr = map[parent[i]];
 
            // if the parent's left child is filled,
            // map the node to its right child
            if (ptr->left) {
                ptr->right = map[i];
            }
            // if the parent's left child is empty, map the node to it
            else {
                ptr->left = map[i];
            }
        }
    }
 
    // return root of the constructed tree
    return root;
}
 
int main()
{
    vector<int> parent = { -1, 0, 0, 1, 2, 2, 4, 4 };
 
    Node* root = createTree(parent);
    inorder(root);
 
    return 0;
}

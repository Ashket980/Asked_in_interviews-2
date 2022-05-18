#include <iostream>
#include <stack>
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
 
// Function to print root-to-leaf paths without using recursion
void printTopToBottomPath(unordered_map<Node*, Node*> parent, Node* node)
{
    while (node = parent[node]) {
        cout << node->data << " ";
    }
    cout << endl;
}
 
// Iterative function to set parent nodes for all nodes of the binary tree
// in a given map. The function is similar to the iterative preorder traversal
void setParent(Node* root, unordered_map<Node*, Node*> &parent)
{
    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // Pop the top item from the stack
        Node* curr = stack.top();
        stack.pop();
 
        // push its right child into the stack and set its parent on the map
        if (curr->right)
        {
            parent[curr->right] = curr;
            stack.push(curr->right);
        }
 
        // push its left child into the stack and set its parent on the map
        if (curr->left)
        {
            parent[curr->left] = curr;
            stack.push(curr->left);
        }
    }
}
 
// Iterative function to print all ancestors of a given node in a binary tree
void printAncestors(Node* root, Node* node)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // create an empty map to store parent pointers of binary tree nodes
    unordered_map<Node*, Node*> parent;
 
    // set the parent of the root node as nullptr
    parent[root] = nullptr;
 
    // set parent nodes for all nodes of the binary tree
    setParent(root, parent);
 
    // print ancestors of a given node using the parent map
    printTopToBottomPath(parent, node);
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

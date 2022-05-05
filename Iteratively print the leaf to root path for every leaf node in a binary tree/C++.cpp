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
 
 
// Function to check if a given node is a leaf node or not
bool isLeaf(Node* node) {
    return (node->left == nullptr && node->right == nullptr);
}
 
// Recursive function to print the root-to-leaf path for a given leaf
void printPathRecursive(Node* curr, unordered_map<Node*, Node*> map)
{
    // base case: `curr` is the root node (parent of the root node is null)
    if (curr == nullptr) {
        return;
    }
 
    // recursively call the parent node
    printPathRecursive(map[curr], map);
    cout << curr->data << (isLeaf(curr) ? "\n" : " —> ");
}
 
// Iterative function to print the leaf-to-root path for a given leaf.
// For printing root-to-leaf path, we can use `printPathRecursive()` or a stack
void printPathIterative(Node* leafNode, unordered_map<Node*, Node*> map)
{
    // start from the leaf node
    Node* curr = leafNode;
 
    // loop till the root node is reached and print each node in the path
    while (map[curr] != nullptr)
    {
        cout << curr->data << " —> ";
        curr = map[curr];
    }
 
    cout << curr->data << endl;
}
 
// Iterative function to print the leaf-to-root path for every leaf node
void postorderIterative(Node* root)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack
    stack<Node*> s;
 
    // create an empty map to store (child, parent) pairs
    unordered_map<Node*, Node*> map;
 
    // parent of the root node is null
    map[root] = nullptr;
 
    // push the root node
    s.push(root);
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop the top node from the stack
        Node* curr = s.top();
        s.pop();
 
        // if a leaf node is found, print the path
        if (isLeaf(curr))
        {
            // print the leaf-to-root path for the current leaf
            printPathIterative(curr, map);
 
            // print root-to-leaf path for the current leaf
            // printPathRecursive(curr, map);
        }
 
        // Push the left and right child of the popped node into the stack.
        // Include the current node's left and right child on a map.
        if (curr->right)
        {
            s.push(curr->right);
            map[curr->right] = curr;
        }
 
        if (curr->left)
        {
            s.push(curr->left);
            map[curr->left] = curr;
        }
    }
}
 
int main()
{
    /* Construct the following tree
                1
              /   \
             /     \
            /       \
           2         3
          / \       / \
         /   \     /   \
        4     5   6     7
                 / \
                /   \
               8     9
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
 
    postorderIterative(root);
 
    return 0;
}

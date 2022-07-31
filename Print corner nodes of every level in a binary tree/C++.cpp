#include <iostream>
#include <queue>
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
 
// Iterative function to print corner nodes of every level in a binary tree
void print(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty queue to store tree nodes
    queue<Node*> q;
 
    // enqueue root node
    q.push(root);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // get the size of the current level
        int size = q.size();
        int n = size;
 
        // process all nodes present in the current level
        while (n--)
        {
            Node* node = q.front();
            q.pop();
 
            // if the corner node is found, print it
            if (n == size - 1 || n == 0) {
                cout << node->data << " ";
            }
 
            // enqueue left and right child of the current node
            if (node->left != nullptr) {
                q.push(node->left);
            }
 
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
 
        // terminate level by printing an empty line
        cout << endl;
    }
}
 
int main()
{
    /* Construct the following tree
                 1
               /   \
              2     3
            /     /   \
           4     5     6
         /     /   \     \
        7     8     9     10
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
    root->right->right->right = new Node(10);
 
    print(root);
 
    return 0;
}

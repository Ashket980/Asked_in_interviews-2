#include <iostream>
#include <list>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Function to find the maximum width of a binary tree using level order
// traversal of a given binary tree
void findMaxWidth(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty queue and enqueue the root node
    list<Node*> queue;
    queue.push_back(root);
 
    // pointer to store the current node
    Node* curr = nullptr;
 
    // stores the maximum width
    int max = 0;
 
    // loop till queue is empty
    while (!queue.empty())
    {
        // calculate the total number of nodes at the current level.
        // This is equal to the width of the current level.
        int width = queue.size();
 
        // update maximum width if the total number of nodes at the current level
        // is more than the maximum width found so far
        if (max < width) {
            max = width;
        }
 
        // process every node of the current level and enqueue their
        // non-empty left and right child
        while (width--)
        {
            curr = queue.front();
            queue.pop_front();
 
            if (curr->left) {
                queue.push_back(curr->left);
            }
 
            if (curr->right) {
                queue.push_back(curr->right);
            }
        }
    }
 
    cout << "The Maximum width is " << max;
}
 
int main()
{
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    findMaxWidth(root);
 
    return 0;
}

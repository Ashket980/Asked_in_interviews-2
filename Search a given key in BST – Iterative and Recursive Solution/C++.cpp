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
 
// Recursive function to search in a given BST
void search(Node* root, int key, Node* parent)
{
    // if the key is not present in the key
    if (root == nullptr)
    {
        cout << "Key not found";
        return;
    }
 
    // if the key is found
    if (root->data == key)
    {
        if (parent == nullptr) {
            cout << "The node with key " << key << " is root node";
        }
        else if (key < parent->data)
        {
            cout << "The given key is the left node of the node with key "
                 << parent->data;
        }
        else  {
            cout << "The given key is the right node of the node with key "
                 << parent->data;
        }
 
        return;
    }
 
    // if the given key is less than the root node, recur for the left subtree;
    // otherwise, recur for the right subtree
 
    if (key < root->data) {
        search(root->left, key, root);
    } else {
        search(root->right, key, root);
    }
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    search(root, 25, nullptr);
 
    return 0;
}

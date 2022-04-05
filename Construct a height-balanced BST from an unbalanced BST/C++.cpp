#include <iostream>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node *left, *right;
 
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Helper function to perform the preorder traversal on a BST
void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}
 
// Function to insert a BST node at the front of a doubly linked list
void push(Node* root, Node*& headRef)
{
    // insert the given node at the front of a DDL
    root->right = headRef;
 
    // update the left pointer of the existing head node of the DDL
    // to point to the BST node
    if (headRef != nullptr) {
        headRef->left = root;
    }
 
    // update the head pointer of DDL
    headRef = root;
}
 
/*
    Recursive function to construct a sorted doubly linked list from a BST
    root —> Pointer to the root node of the binary search tree
    headRef —> Reference to the head node of the doubly linked list
    n —> Stores the total number of nodes processed so far in the BST
*/
void convertBSTtoSortedDLL(Node* root, Node*& headRef, int &n)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // recursively convert the right subtree
    convertBSTtoSortedDLL(root->right, headRef, n);
 
    // push the current node at the front of the doubly linked list
    push(root, headRef);
 
    // recursively convert the left subtree
    convertBSTtoSortedDLL(root->left, headRef, ++n);
}
 
/*
    Recursive function to construct a height-balanced BST from a doubly linked list
    headRef —> Reference to the head node of the doubly linked list
    n —> Total number of nodes in the doubly linked list
*/
Node* convertSortedDLLToBST(Node* &headRef, int n)
{
    // base case
    if (n <= 0) {
        return nullptr;
    }
 
    // recursively construct the left subtree
    Node* leftSubTree = convertSortedDLLToBST(headRef, n/2);
 
    // `headRef` now points to the middle node of the sorted DDL
 
    // make the middle node of the sorted DDL as the root node of the BST
    Node* root = headRef;
 
    // update left child of the root node
    root->left = leftSubTree;
 
    // update the head reference of the doubly linked list
    headRef = headRef->right;
 
    // recursively construct the right subtree with the remaining nodes
    root->right = convertSortedDLLToBST(headRef, n - (n/2 + 1));
                                                /* +1 for the root node */
 
    // return the root node
    return root;
}
 
// Function to construct a height-balanced BST from an unbalanced BST
void constructBalancedBST(Node* &root)
{
    // pointer to the head node of the doubly linked list
    Node* head = nullptr;
 
    // convert the given BST into a sorted doubly linked list and update the counter
    // with the total number of nodes in the BST
    int counter = 0;
    convertBSTtoSortedDLL(root, head, counter);
 
    // construct a height-balanced BST from the sorted doubly linked list
    root = convertSortedDLLToBST(head, counter);
}
 
int main()
{
    Node* root = new Node(20);
    root->left = new Node(15);
    root->left->left = new Node(10);
    root->left->left->left = new Node(5);
    root->left->left->left->left = new Node(2);
    root->left->left->left->right = new Node(8);
 
    constructBalancedBST(root);
 
    cout << "Preorder traversal of the constructed BST is ";
    preorder(root);
 
    return 0;
}

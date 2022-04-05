#include <iostream>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node* left, *right;
 
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Helper function to print a doubly linked list
void printDoublyLinkedList(Node* head)
{
    while (head)
    {
        cout << head->data << " —> ";
        head = head->right;
    }
 
    cout << "null" << endl;
}
 
// Function to insert a BST node at the front of a doubly linked list
void push(Node* root, Node* &headRef)
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
    Recursive function to convert a binary search tree into a doubly linked list
    root    ——> Pointer to the root node of the binary search tree
    headRef ——> Reference to the head node of the doubly linked list
*/
Node* convertBSTtoDLL(Node* root, Node* &headRef)
{
    // Base case
    if (root == nullptr) {
        return nullptr;
    }
 
    // recursively convert the right subtree
    convertBSTtoDLL(root->right, headRef);
 
    // push the current node at the front of the doubly linked list
    push(root, headRef);
 
    // recursively convert the left subtree
    convertBSTtoDLL(root->left, headRef);
}
 
// Recursive function to merge two doubly-linked lists into a
// single doubly linked list in sorted order
Node* mergeDDLs(Node* a, Node* b)
{
    // if the first list is empty, return the second list
    if (a == nullptr) {
        return b;
    }
 
    // if the second list is empty, return the first list
    if (b == nullptr) {
        return a;
    }
 
    // if the head node of the first list is smaller
    if (a->data < b->data)
    {
        a->right = mergeDDLs(a->right, b);
        a->right->left = a;
 
        return a;
    }
 
    // if a head node of the second list is smaller
    else {
        b->right = mergeDDLs(a, b->right);
        b->right->left = b;
 
        return b;
    }
}
 
// Function to merge two binary search trees into a doubly-linked list
// in sorted order
Node* merge(Node* a, Node* b)
{
    // convert the first binary search tree into a doubly-linked list
    Node* first = nullptr;
    convertBSTtoDLL(a, first);
 
    // convert the second binary search tree into a doubly-linked list
    Node* second = nullptr;
    convertBSTtoDLL(b, second);
 
    // merge both doubly-linked lists
    return mergeDDLs(first, second);
}
 
int main()
{
    /* Construct the following BST
          20
         /  \
       10    30
            /  \
           25  100
    */
 
    Node* a = new Node(20);
    a->left = new Node(10);
    a->right = new Node(30);
    a->right->left = new Node(25);
    a->right->right = new Node(100);
 
    /* Construct the following BST
          50
         /  \
        5   70
    */
 
    Node* b = new Node(50);
    b->left = new Node(5);
    b->right = new Node(70);
 
    // merge both BSTs into a doubly-linked list
    Node* root = merge(a, b);
    printDoublyLinkedList(root);
 
    return 0;
}

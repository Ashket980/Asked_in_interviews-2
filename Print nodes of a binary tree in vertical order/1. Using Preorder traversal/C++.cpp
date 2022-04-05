#include <iostream>
#include <vector>
using namespace std;
 
// Data structure to store a binary tree node
struct TreeNode
{
    int data;
    TreeNode *left, *right;
 
    TreeNode(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// A Doubly Linked List Node
struct ListNode
{
    vector<int> data;
    ListNode *prev, *next;
 
    ListNode(int data, ListNode* prev, ListNode* next)
    {
        (this->data).push_back(data);
        this->prev = prev;
        this->next = next;
    }
 
    ListNode(ListNode* prev, ListNode* next)
    {
        this->prev = prev;
        this->next = next;
    }
};
 
// Function to print the vertical order stored in a given doubly linked list
void print(ListNode* mid)
{
    // find the head node
    while (mid && mid->prev) {
        mid = mid->prev;
    }
 
    // start with the head node
    ListNode* head = mid;
    while (head)
    {
        for (int i: head->data) {
            cout << i << ' ';
        }
        cout << endl;
        head = head->next;
    }
}
 
// Recursive function to perform preorder traversal on the tree and
// determine the vertical order of the given binary tree.
// Each node of the doubly linked list will store nodes present at the
// corresponding vertical line in a binary tree.
void updateDLLwithVerticalOrder(TreeNode* root, ListNode* curr)
{
    // base case
    if (!root) {
        return;
    }
 
    // add the current tree node to the corresponding list node
    curr->data.push_back(root->data);
 
    // create a new linked list node corresponding to the vertical line passing
    // through the root's left child, if not already.
    // This node would become the `prev` pointer of the current list node
    if (root->left && !curr->prev) {
        curr->prev = new ListNode(nullptr, curr);
    }
 
    // create a new linked list node corresponding to the vertical line passing
    // through the root's right child, if not already.
    // This node would become the `next` pointer of the current list node
    if (root->right && !curr->next) {
        curr->next = new ListNode(curr, nullptr);
    }
 
    // recur for the left and right subtree
    updateDLLwithVerticalOrder(root->left, curr->prev);
    updateDLLwithVerticalOrder(root->right, curr->next);
}
 
// Function to print nodes of a given binary tree in vertical order
void printVertical(TreeNode* root)
{
    // create a new linked list node corresponding to the vertical line passing
    // through the root node
    ListNode* curr = new ListNode(nullptr, nullptr);
 
    // determine the vertical order and store it in a doubly-linked list
    updateDLLwithVerticalOrder(root, curr);
 
    // print the linked list
    print(curr);
}
 
int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
                /   \
               /     \
              5       6
            /   \
           /     \
          7       8
                /   \
               /     \
              9      10
    */
 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->left->right->left = new TreeNode(9);
    root->right->left->right->right = new TreeNode(10);
 
    printVertical(root);
 
    return 0;
}

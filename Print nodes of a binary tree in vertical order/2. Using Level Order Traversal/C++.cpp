#include <iostream>
#include <queue>
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
 
// Function to perform level order traversal on the tree and determine
// the vertical order of a given binary tree.
// Each node of the doubly linked list will store nodes present at the
// corresponding vertical line in a binary tree.
void updateDLLwithVerticalOrder(TreeNode* root, ListNode* curr)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // create an empty queue for level order traversal and
    // enqueue root node with its corresponding linked list node
    queue<pair<TreeNode*, ListNode*>> q;
    q.push(make_pair(root, curr));
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        TreeNode* node = q.front().first;   // tree node
        ListNode* curr = q.front().second;  // list node
        q.pop();
 
        // push the value of the current tree node into the corresponding list node
        curr->data.push_back(node->data);
 
        // process non-empty left child
        if (node->left)
        {
            // create a new linked list node corresponding to the vertical line passing
            // through the node's left child, if not already.
            // This node would become the `prev` pointer of the current list node
            if (!curr->prev) {
                curr->prev = new ListNode(nullptr, curr);
            }
 
            // enqueue left child with its corresponding linked list node
            q.push(make_pair(node->left, curr->prev));
        }
 
        // process non-empty right child
        if (node->right)
        {
            // create a new linked list node corresponding to the vertical line passing
            // through the node's right child, if not already.
            // This node would become the `next` pointer of the current list node
            if (!curr->next) {
                curr->next = new ListNode(curr, nullptr);
            }
 
            // enqueue right child with its corresponding linked list node
            q.push(make_pair(node->right, curr->next));
        }
    }
}
 
// Function to print nodes of a given binary tree in vertical order
void printVertical(TreeNode* root)
{
    // create a new linked list node corresponding to the vertical line passing
    // through the root node
    ListNode* curr = new ListNode(nullptr, nullptr);
 
    // determine vertical order and store it in a doubly-linked list
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

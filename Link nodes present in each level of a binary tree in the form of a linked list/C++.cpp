#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right, *next;
 
    // constructor
    Node(int data)
    {
        this->data = data;
        this->left = this->right = this->next = nullptr;
    }
};
 
// Function to print a given linked list
void printList(Node* head)
{
    while (head)
    {
        cout << head->data << " —> ";
        head = head->next;
    }
 
    cout << "null" << endl;
}
 
// Recursive function to find the first node in the next level of a given root node
Node* findNextNode(Node* root)
{
    // base case
    if (root == nullptr || root->next == nullptr) {
        return nullptr;
    }
 
    // if the left child of the root's next node exists, return it
    if (root->next->left) {
        return root->next->left;
    }
 
    // if the right child of the root's next node exists, return it
    if (root->next->right) {
        return root->next->right;
    }
 
    // if root's next node is a leaf node, recur for root's next node
    return findNextNode(root->next);
}
 
// Function to traverse the nodes in a preorder fashion and
// insert all nodes into the map corresponding to their level
void linkNodes(Node* root, int level, auto &map)
{
    // base case: empty subtree
    if (root == nullptr) {
        return;
    }
 
    // insert the current node and level information into the map
    map[level].push_back(root);
 
    // recur for the left and right subtree by increasing the level by 1
    linkNodes(root->left, level + 1, map);
    linkNodes(root->right, level + 1, map);
}
 
// Function to link nodes present in each level of a binary tree
// using the next pointer
void linkNodes(Node* root)
{
    // create an empty map to store nodes present at each level
    // from left to right
    unordered_map<int, vector<Node*>> map;
 
    // traverse the tree in a preorder fashion and fill the map
    linkNodes(root, 1, map);
 
    // iterate through the map, and for each level,
    // set the next node for every node in it
    for (auto it: map)
    {
        Node* prev = nullptr;
        for (Node* curr: it.second)
        {
            if (prev) {
                prev->next = curr;
            }
            prev = curr;
        }
        prev->next = nullptr;
    }
};
 
int main()
{
    /* Construct the following tree
           1
         /   \
        2     3
       / \     \
      4   5     6
       \       /
        7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->right = new Node(7);
    root->right->right->left = new Node(8);
 
    // link nodes at the same level
    linkNodes(root);
 
    // print the nodes
    Node* node = root;
    while (node)
    {
        // print the current level
        printList(node);
 
        // find the leftmost node in the next level
        if (node->left) {
            node = node->left;
        }
        else if (node->right) {
            node = node->right;
        }
        else {
            node = findNextNode(node);
        }
    }
 
    return 0;
}

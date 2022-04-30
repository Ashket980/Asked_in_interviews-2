#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
 
// Recursive function to find preorder traversal of a binary tree
// from its inorder and postorder sequence.
void printPreorder(int start, int end,
                vector<int> const &postorder, int &pIndex,
                unordered_map<int, int> &map, stack<int> &stack)
{
    // base case
    if (start > end) {
        return;
    }
 
    // The next element in the postorder sequence from the end will be the root node
    // of subtree formed by sequence inorder[start, end]
    int value = postorder[pIndex--];
 
    // get the current node index in inorder sequence to determine
    // its left and right subtree boundary
    int index = map[value];
 
    // recur for the right subtree
    printPreorder(index + 1, end, postorder, pIndex, map, stack);
 
    // recur for the left subtree
    printPreorder(start, index - 1, postorder, pIndex, map, stack);
 
    // push the value of the current node into the stack
    stack.push(value);
}
 
// Find preorder traversal of a binary tree from its inorder and
// postorder sequence. This function assumes that the input is valid.
// i.e., given inorder and postorder sequence forms a binary tree.
void findPreorder(vector<int> const &inorder, vector<int> const &postorder)
{
    // map is used to efficiently find the index of any element in
    // a given inorder sequence
    unordered_map<int, int> map;
 
    // fill the map
    for (int i = 0; i < inorder.size(); i++) {
        map[inorder[i]] = i;
    }
 
    // `lastIndex` stores the index of the next unprocessed node from the end
    // of the postorder sequence
    int lastIndex = inorder.size() - 1;
 
    // construct a stack to store the preorder sequence
    stack<int> stack;
 
    // fill the stack
    printPreorder(0, lastIndex, postorder, lastIndex, map, stack);
 
    // print the stack
    cout << "The preorder traversal is ";
    while (!stack.empty())
    {
        cout << stack.top() << ' ';
        stack.pop();
    }
}
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /       / \
         /       /   \
        4       5     6
               / \
              /   \
             7     8
    */
 
    vector<int> inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
    vector<int> postorder = { 4, 2, 7, 8, 5, 6, 3, 1 };
 
    findPreorder(inorder, postorder);
 
    return 0;
}

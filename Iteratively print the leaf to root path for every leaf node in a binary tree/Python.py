from collections import deque
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Function to check if a given node is a leaf node or not
def isLeaf(node):
    return node.left is None and node.right is None
 
 
# Recursive function to print the root-to-leaf path for a given leaf
def printPathRecursive(curr, d):
 
    # base case: `curr` is the root node (parent of the root node is None)
    if curr is None:
        return
 
    # recursively call the parent node
    printPathRecursive(d[curr], d)
    print(curr.data, end=' —> ')
 
 
# Iterative function to print the leaf-to-root path for a given leaf.
# For printing root-to-leaf path, we can use `printPathRecursive()` or a stack
def printPathIterative(leafNode, d):
 
    # start from the leaf node
    curr = leafNode
 
    # loop till the root node is reached and print each node in the path
    while d[curr]:
        print(curr.data, end=' —> ')
        curr = d[curr]
 
    print(curr.data)
 
 
# Iterative function to print the leaf-to-root path for every leaf node
def postorderIterative(root):
 
    # base case
    if not root:
        return
 
    # create an empty stack
    s = deque()
 
    # create an empty dictionary to store (child, parent) pairs
    d = {}
 
    # parent of the root node is None
    d[root] = None
 
    # push the root node
    s.append(root)
 
    # loop till stack is empty
    while s:
 
        # pop the top node from the stack
        curr = s.pop()
 
        # if a leaf node is found, print the path
        if isLeaf(curr):
            # print the leaf-to-root path for the current leaf
            printPathIterative(curr, d)
 
        # print root-to-leaf path for the current leaf
        # printPathRecursive(curr, d)
 
        # Push the left and right child of the popped node into the stack.
        # Include the current node's left and right child in a dictionary
        if curr.right:
            s.append(curr.right)
            d[curr.right] = curr
 
        if curr.left:
            s.append(curr.left)
            d[curr.left] = curr
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
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
    '''
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.right.left.left = Node(8)
    root.right.left.right = Node(9)
 
    postorderIterative(root)

from collections import deque
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Function to print root-to-leaf paths without using recursion
def printTopToBottomPath(parent, node):
    while node:
        print(node.data, end=' ')
        node = parent.setdefault(node, None)
 
 
# Iterative function to set parent nodes for all nodes of the binary tree
# in a given dict. The function is similar to the iterative preorder traversal
def setParent(root, parent):
 
    # create an empty stack and push the root node
    stack = deque()
    stack.append(root)
 
    # loop till stack is empty
    while stack:
 
        # Pop the top item from the stack
        curr = stack.pop()
 
        # push its right child into the stack and set its parent on the dictionary
        if curr.right:
            parent[curr.right] = curr
            stack.append(curr.right)
 
        # push its left child into the stack and set its parent on the dictionary
        if curr.left:
            parent[curr.left] = curr
            stack.append(curr.left)
 
 
# Iterative function to print all ancestors of a given node in a binary tree
def printAncestors(root, node):
 
    # base case
    if root is None:
        return
 
    # create an empty dictionary to store parent pointers of binary tree nodes.
    # set the parent of the root node as None
    parent = {root: None}
 
    # set parent nodes for all nodes of the binary tree
    setParent(root, parent)
 
    # print ancestors of a given node using the parent dictionary
    printTopToBottomPath(parent, parent.setdefault(node, None))
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
            1
          /   \
         /     \
        2       3
         \     / \
          4   5   6
             / \
            7   8
    '''
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(4)
    root.right.left = Node(5)
    root.right.right = Node(6)
    root.right.left.left = Node(7)
    root.right.left.right = Node(8)
 
    node = root.right.left.left        # Node 7
    printAncestors(root, node)

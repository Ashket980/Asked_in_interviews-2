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
 
 
# Recursive function to print all paths from leaf-to-root node
def printLeafToRootPaths(node, path):
 
    # base case
    if node is None:
        return
 
    # include the current node to the path
    path.append(node.data)
 
    # if a leaf node is found, print the path present in the list
    # in reverse order (leaf to the root node)
    if isLeaf(node):
        print(list(reversed(path)))
 
    # recur for the left and right subtree
    printLeafToRootPaths(node.left, path)
    printLeafToRootPaths(node.right, path)
 
    # backtrack: remove the current node after the left, and right subtree are done
    path.pop()
 
 
# The main function to print all paths from leaf-to-root node
def findLeafToRootPaths(node):
 
    # Deque to store leaf-to-root path
    path = deque()
 
    # call recursive function
    printLeafToRootPaths(node, path)
 
 
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
 
    # print all leaf-to-root paths
    findLeafToRootPaths(root)

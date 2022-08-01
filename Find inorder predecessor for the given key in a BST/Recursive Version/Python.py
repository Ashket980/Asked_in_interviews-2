# A class to store a BST node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Recursive function to insert a key into a BST
def insert(root, key):
 
    # if the root is None, create a new node and return it
    if root is None:
        return Node(key)
 
    # if the given key is less than the root node, recur for the left subtree
    if key < root.data:
        root.left = insert(root.left, key)
 
    # if the given key is more than the root node, recur for the right subtree
    else:
        root.right = insert(root.right, key)
 
    return root
 
 
# Helper function to find the maximum value node in a given BST
def findMaximum(root):
    while root.right:
        root = root.right
    return root
 
 
# Recursive function to find inorder predecessor for a given key in a BST
def findPredecessor(root, prec, key):
 
    # base case
    if root is None:
        return prec
 
    # if a node with the desired value is found, the predecessor is the maximum value
    # node in its left subtree (if any)
    if root.data == key:
        if root.left:
            return findMaximum(root.left)
 
    # if the given key is less than the root node, recur for the left subtree
    elif key < root.data:
        return findPredecessor(root.left, prec, key)
 
    # if the given key is more than the root node, recur for the right subtree
    else:
        # update predecessor to the current node before recursing
        # in the right subtree
        prec = root
        return findPredecessor(root.right, prec, key)
 
    return prec
 
 
if __name__ == '__main__':
 
    keys = [15, 10, 20, 8, 12, 16, 25]
 
    ''' Construct the following tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
    '''
 
    root = None
    for key in keys:
        root = insert(root, key)
 
    # find inorder predecessor for each key
    for key in keys:
        prec = findPredecessor(root, None, key)
 
        if prec:
            print(f'Predecessor of node {key} is {prec.data}')
        else:
            print('The predecessor doesn\'t exist for node', key)

import sys
 
 
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
 
 
# Function to perform inorder traversal on the given binary tree and
# check if it is a BST or not. Here, `prev` is the previously processed node
def isBST(root, prev):
 
    # base case: empty tree is a BST
    if root is None:
        return True
 
    # check if the left subtree is BST or not
    left = isBST(root.left, prev)
 
    # value of the current node should be more than that of the previous node
    if root.data <= prev.data:
        return False
 
    # update previous node data and check if the right subtree is BST or not
    prev.data = root.data
    return left and isBST(root.right, prev)
 
 
# Function to determine whether a given binary tree is a BST
def checkForBST(node):
 
    # pointer to store previously processed node in the inorder traversal
    prev = Node(-sys.maxsize)
 
    # check if nodes are processed in sorted order
    if isBST(node, prev):
        print('The tree is a BST!')
    else:
        print('The tree is not a BST!')
 
 
def swap(root):
 
    left = root.left
    root.left = root.right
    root.right = left
 
 
if __name__ == '__main__':
 
    keys = [15, 10, 20, 8, 12, 16, 25]
 
    root = None
    for key in keys:
        root = insert(root, key)
 
    # swap nodes
    swap(root)
    checkForBST(root)

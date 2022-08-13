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
 
# Iterative function to search in a given BST
def searchIterative(root, key):
 
    # start with the root node
    curr = root
 
    # pointer to store the parent of the current node
    parent = None
 
    # traverse the tree and search for the key
    while curr and curr.data != key:
 
        # update the parent to the current node
        parent = curr
 
        # if the given key is less than the current node, go to the left subtree;
        # otherwise, go to the right subtree
        if key < curr.data:
            curr = curr.left
        else:
            curr = curr.right
 
    # if the key is not present in the key
    if curr is None:
        print('Key not found')
        return
 
    if parent is None:
        print(f'The node with key {key} is root node')
    elif key < parent.data:
        print('The given key is the left node of the node with key', parent.data)
    else:
        print('The given key is the right node of the node with key', parent.data)
 
 
if __name__ == '__main__':
 
    keys = [15, 10, 20, 8, 12, 16, 25]
 
    root = None
    for key in keys:
        root = insert(root, key)
 
    searchIterative(root, 25)

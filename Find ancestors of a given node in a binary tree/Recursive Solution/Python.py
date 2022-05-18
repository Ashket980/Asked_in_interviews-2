
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Recursive function to print all ancestors of a given node in a binary tree.
# The function returns true if the node is found in the subtree rooted at the
# given root node.
def printAncestors(root, node):
 
    # base case
    if root is None:
        return False
 
    # return true if a given node is found
    if root == node:
        return True
 
    # search node in the left subtree
    left = printAncestors(root.left, node)
 
    # search node in the right subtree
    right = False
    if not left:
        right = printAncestors(root.right, node)
 
    # if the given node is found in either left or right subtree,
    # the current node is an ancestor of a given node
    if left or right:
        print(root.data, end=' ')
 
    # return true if a node is found
    return left or right
 
 
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

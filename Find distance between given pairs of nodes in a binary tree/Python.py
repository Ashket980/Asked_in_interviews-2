import sys
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Function to check if a given node is present in a binary tree or not
def isNodePresent(root, node):
 
    # base case
    if root is None:
        return False
 
    # if the node is found, return true
    if root == node:
        return True
 
    # return true if the node is found in the left or right subtree
    return isNodePresent(root.left, node) or isNodePresent(root.right, node)
 
 
# Function to find the level of a given node present in a binary tree
def findLevel(root, node, level):
 
    # base case
    if root is None:
        return -sys.maxsize
 
    # return level if the node is found
    if root == node:
        return level
 
    # search node in the left subtree
    left = findLevel(root.left, node, level + 1)
 
    # if the node is found in the left subtree, return the left child
    if left != -sys.maxsize:
        return left
 
    # otherwise, continue the search in the right subtree
    return findLevel(root.right, node, level + 1)
 
 
# Function to find the lowest common ancestor of given nodes `x` and `y`,
# where both `x` and `y` are present in a binary tree.
def findLCA(root, x, y):
 
    # base case 1: if the tree is empty
    if root is None:
        return None
 
    # base case 2: if either `x` or `y` is found
    if root == x or root == y:
        return root
 
    # recursively check if `x` or `y` exists in the left subtree
    left = findLCA(root.left, x, y)
 
    # recursively check if `x` or `y` exists in the right subtree
    right = findLCA(root.right, x, y)
 
    # if `x` is found in one subtree and `y` is found in the other subtree,
    # update lca to the current node
    if left and right:
        return root
 
    # if `x` and `y` exist in the left subtree
    if left:
        return left
 
    # if `x` and `y` exist in the right subtree
    if right:
        return right
 
    return None
 
 
# Function to find the distance between node `x` and node `y` in a
# given binary tree rooted at `root` node
def findDistance(root, x, y):
 
    # `lca` stores the lowest common ancestor of `x` and `y`
    lca = None
 
    # call LCA procedure only if both `x` and `y` are present in the tree
    if isNodePresent(root, y) and isNodePresent(root, x):
        lca = findLCA(root, x, y)
    else:
        return -sys.maxsize
 
    # return distance of `x` from lca + distance of `y` from lca
    return findLevel(lca, x, 0) + findLevel(lca, y, 0)
 
    '''
        The above statement is equivalent to the following:
 
        return findLevel(root, x, 0) + findLevel(root, y, 0) -
                2*findLevel(root, lca, 0)
 
        We can avoid calling the `isNodePresent()` function by using
        return values of the `findLevel()` function to check if
        `x` and `y` are present in the tree or not.
    '''
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
          1
        /   \
       /     \
      2       3
       \     / \
        4   5   6
           /     \
          7       8
    '''
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(4)
    root.right.left = Node(5)
    root.right.right = Node(6)
    root.right.left.left = Node(7)
    root.right.right.right = Node(8)
 
    # find the distance between node 7 and node 6
    print(findDistance(root, root.right.left.left, root.right.right))

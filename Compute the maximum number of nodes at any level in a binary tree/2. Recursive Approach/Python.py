# A class to store a binary tree node
class Node:
    def __init__(self, key=None, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right
 
 
# Traverse the tree in a preorder fashion and store the count of nodes
# in each level
def preorder(root, level, dict):
 
    # base case: empty tree
    if not root:
        return
 
    # increment count of nodes at the current level
    dict[level] = dict.get(level, 0) + 1
 
    # recur for the left and right subtree by increasing the level by 1
    preorder(root.left, level + 1, dict)
    preorder(root.right, level + 1, dict)
 
 
# Recursive function to find the maximum width of a binary tree
def findMaxWidth(root):
 
    # base case
    if not root:
        return 0
 
    # create an empty dictionary to store the count of nodes in each level
    dict = {}
 
    # traverse the tree and fill the dictionary
    preorder(root, 1, dict)
 
    # iterate through the dictionary and find maximum width
    print('The maximum width is', max(dict.values()))
 
 
if __name__ == '__main__':
 
    root = Node(15)
    root.left = Node(10)
    root.right = Node(20)
    root.left.left = Node(8)
    root.left.right = Node(12)
    root.right.left = Node(16)
    root.right.right = Node(25)
 
    findMaxWidth(root)

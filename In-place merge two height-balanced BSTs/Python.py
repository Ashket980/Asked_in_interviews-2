# A BST node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
    def __repr__(self):
        return str(self.data)
 
 
# Function to print preorder traversal of the BST
def preorder(root):
    if root is None:
        return
    print(root.data, end=' ')
    preorder(root.left)
    preorder(root.right)
 
 
# Function to store inorder traversal of a BST in a given list
def inorder(root, nodes):
    if root is None:
        return
    inorder(root.left, nodes)
    nodes.append(root)
    inorder(root.right, nodes)
 
 
# Function to merge two sorted lists into a single sorted list
def sortedMerge(first, second):
    result = []
    i = j = 0
 
    while i < len(first) and j < len(second):
        # if the next node of the first list is smaller
        if first[i].data < second[j].data:
            result.append(first[i])
            i = i + 1
        # if the next node of the second list is smaller
        else:
            result.append(second[j])
            j = j + 1
 
    # add any remaining nodes to the output list
 
    while i < len(first):
        result.append(first[i])
        i = i + 1
 
    while j < len(second):
        result.append(second[j])
        j = j + 1
 
    return result
 
 
# Function to construct a balanced BST from a sorted list
def toBalancedBST(nodes, low, high):
    if low > high:        # base case
        return None
 
    # find the middle of the current range
    mid = (low + high) // 2
 
    # `root` is the node corresponding to `mid`
    root = nodes[mid]
 
    # construct left subtree from nodes less than `mid`
    root.left = toBalancedBST(nodes, low, mid - 1)
 
    # construct the right subtree from nodes more than `mid`
    root.right = toBalancedBST(nodes, mid + 1, high)
 
    # return root node
    return root
 
 
# Function to merge two balanced BSTs into a single balanced BST
def merge(a, b):
 
    # store inorder traversal of the first BST in a list
    first = []
    inorder(a, first)
 
    # store inorder traversal of the second BST in another list
    second = []
    inorder(b, second)
 
    # merge both lists into a new sorted list
    sortedNodes = sortedMerge(first, second)
 
    # construct and return the balanced BST from the sorted list
    return toBalancedBST(sortedNodes, 0, len(sortedNodes) - 1)
 
 
if __name__ == '__main__':
 
    '''
    Construct the first BST
          20
         /  \
        10  30
            / \
           25 100
    '''
 
    first = Node(20)
    first.left = Node(10)
    first.right = Node(30)
    first.right.left = Node(25)
    first.right.right = Node(100)
 
    '''
    Construct the second BST
          50
         /  \
        5   70
    '''
 
    second = Node(50)
    second.left = Node(5)
    second.right = Node(70)
 
    # merge both BSTs
    root = merge(first, second)
    preorder(root)

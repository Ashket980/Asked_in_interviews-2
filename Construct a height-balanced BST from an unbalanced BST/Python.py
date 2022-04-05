# A class to store a BST node
class Node:
    # Constructor
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Helper function to perform the preorder traversal on a BST
def preorder(root):
    if root is None:
        return
    preorder(root.left)
    print(root.data, end=' ')
    preorder(root.right)
 
 
# Function to insert a BST node at the front of a doubly linked list
def push(root, head):
 
    # insert the given node at the front of a DDL
    root.right = head
 
    # update the left child of the existing head node of the DDL
    # to point to the BST node
    if head is not None:
        head.left = root
 
    # update the head pointer of DDL
    head = root
    return head
 
 
'''
Recursive function to construct a sorted doubly linked list from a BST
    root —> Pointer to the root node of the binary search tree
    head —> Reference to the head node of the doubly linked list
    nodes —> Stores the total number of nodes processed so far in the BST
'''
def convertBSTtoSortedDLL(root, head, nodes=0):
 
    # base case
    if root is None:
        return head, nodes
 
    # recursively convert the right subtree
    head, nodes = convertBSTtoSortedDLL(root.right, head, nodes)
 
    # push the current node at the front of the doubly linked list
    head = push(root, head)
 
    # increment the number of nodes
    nodes = nodes + 1
 
    # recursively convert the left subtree
    head, nodes = convertBSTtoSortedDLL(root.left, head, nodes)
 
    return head, nodes
 
 
'''
Recursive function to construct a height-balanced BST from a doubly linked list
    head —> Reference to the head node of the doubly linked list
    n —> Total number of nodes in the doubly linked list
'''
def convertSortedDLLToBST(head, n):
 
    # base case
    if n <= 0:
        return None, head
 
    # recursively construct the left subtree
    leftSubTree, head = convertSortedDLLToBST(head, n // 2)
 
    # `head` now points to the middle node of the sorted DDL
 
    # make the middle node of the sorted DDL as the root node of the BST
    root = head
 
    # update left child of the root node
    root.left = leftSubTree
 
    # update the head reference of the doubly linked list
    head = head.right
 
    # recursively construct the right subtree with the remaining nodes
    root.right, head = convertSortedDLLToBST(head, n - (n // 2 + 1))
                                                    # +1 for root Node
 
    # return the root node
    return root, head
 
 
# Function to construct a height-balanced BST from an unbalanced BST
def constructBalancedBST(root):
 
    # pointer to the head node of the doubly linked list
    head = None
 
    # convert the given BST into a sorted doubly linked list
    head, nodes = convertBSTtoSortedDLL(root, head)
 
    # construct a height-balanced BST from the sorted doubly linked list
    root, head = convertSortedDLLToBST(head, nodes)
 
    return root
 
 
if __name__ == '__main__':
 
    root = Node(20)
    root.left = Node(15)
    root.left.left = Node(10)
    root.left.left.left = Node(5)
    root.left.left.left.left = Node(2)
    root.left.left.left.right = Node(8)
 
    root = constructBalancedBST(root)
 
    print('Preorder traversal of the constructed BST is', end=' ')
    preorder(root)

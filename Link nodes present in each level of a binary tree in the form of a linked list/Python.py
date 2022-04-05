# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None, next=None):
        self.data = data
        self.left = left
        self.right = right
        self.next = next
 
# Function to print a given linked list
def printList(head):
 
    while head:
        print(head.data, end=' —> ')
        head = head.next
 
    print('None')
 
 
# Function to perform inorder traversal on a given binary tree where nodes
# at the same level are linked together in the form of a linked list
def inorder(root):
 
    if root is None:
        return
 
    inorder(root.left)
 
    # print current node and its next node
    print(root.data, end=' —> ')
    if root.next:
        print(root.next.data)
    else:
        print('None')
 
    inorder(root.right)
 
 
# Recursive function to find the first node in the next level of a given root node
def findNextNode(root):
 
    # base case
    if root is None or root.next is None:
        return None
 
    # if the left child of the root's next node exists, return it
    if root.next.left:
        return root.next.left
 
    # if the right child of the root's next node exists, return it
    if root.next.right:
        return root.next.right
 
    # if root's next node is a leaf node, recur for root's next node
    return findNextNode(root.next)
 
 
# Function to traverse the nodes in a preorder fashion and
# insert all nodes into the dictionary corresponding to their level
def linkNodes(root, level, d):
 
    # base case: empty subtree
    if root is None:
        return
 
    # insert the current node and level information into the dictionary
    d.setdefault(level, []).append(root)
 
    # recur for the left and right subtree by increasing the level by 1
    linkNodes(root.left, level + 1, d)
    linkNodes(root.right, level + 1, d)
 
 
# Function to link nodes present in each level of a binary tree
# using the next pointer
def linkNodesBT(root):
 
    # create an empty dictionary to store nodes present at each level
    # from left to right
    d = {}
 
    # traverse the tree in a preorder fashion and fill the dictionary
    linkNodes(root, 1, d)
 
    # iterate through the dictionary, and for each level,
    # set the next node for every node in it
    for values in d.values():
        prev = None
        for curr in values:
            if prev:
                prev.next = curr
            prev = curr
        prev.next = None
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
           1
         /   \
        2     3
       / \     \
      4   5     6
       \       /
        7     8
    '''
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.right = Node(6)
    root.left.left.right = Node(7)
    root.right.right.left = Node(8)
 
    # link nodes at the same level
    linkNodesBT(root)
 
    # print the nodes
    node = root
    while node:
        printList(node)        # print the current level
 
        # find the leftmost node in the next level
        if node.left:
            node = node.left
        elif node.right:
            node = node.right
        else:
            node = findNextNode(node)

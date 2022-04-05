from collections import deque
 
 
# Data structure to store a binary tree node
class TreeNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# A Doubly Linked List Node
class ListNode:
    def __init__(self, prev=None, next=None):
        self.data = []
        self.prev = prev
        self.next = next
 
 
# Function to print the vertical order stored in a given doubly linked list
def printList(mid):
 
    # find the head node
    while mid and mid.prev:
        mid = mid.prev
 
    # start with the head node
    head = mid
    while head:
        print(head.data)
        head = head.next
 
 
# Function to perform level order traversal on the tree and determine the
# vertical order of a given binary tree.
# Each node of the doubly linked list will store nodes present at the corresponding
# vertical line in a binary tree.
def updateDLLwithVerticalOrder(root, curr):
 
    # base case
    if root is None:
        return
 
    # create an empty queue for level order traversal and
    # enqueue root node with its corresponding linked list node
    q = deque()
    q.append((root, curr))
 
    # loop till queue is empty
    while q:
 
        # dequeue front node
        node, curr = q.popleft()
 
        # push the value of the current tree node into the corresponding list node
        curr.data.append(node.data)
 
        # process non-empty left child
        if node.left:
            # create a new linked list node corresponding to the vertical line passing
            # through the node's left child, if not already.
            # This node would become the `prev` pointer of the current list node
            if curr.prev is None:
                curr.prev = ListNode(None, curr)
 
            # enqueue left child with its corresponding linked list node
            q.append((node.left, curr.prev))
 
        # process non-empty right child
        if node.right:
            # create a new linked list node corresponding to the vertical line passing
            # through the node's right child, if not already.
            # This node would become the `next` pointer of the current list node
            if curr.next is None:
                curr.next = ListNode(curr, None)
 
            # enqueue right child with its corresponding linked list node
            q.append((node.right, curr.next))
 
 
# Function to print nodes of a given binary tree in vertical order
def printVertical(root):
 
    # create a new linked list node corresponding to the vertical line passing
    # through the root node
    curr = ListNode()
 
    # determine vertical order and store it in a doubly-linked list
    updateDLLwithVerticalOrder(root, curr)
 
    # print the linked list
    printList(curr)
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
              1
            /   \
           /     \
          2       3
                /   \
               /     \
              5       6
            /   \
           /     \
          7       8
                /   \
               /     \
              9      10
    '''
 
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.right.left = TreeNode(5)
    root.right.right = TreeNode(6)
    root.right.left.left = TreeNode(7)
    root.right.left.right = TreeNode(8)
    root.right.left.right.left = TreeNode(9)
    root.right.left.right.right = TreeNode(10)
 
    printVertical(root)

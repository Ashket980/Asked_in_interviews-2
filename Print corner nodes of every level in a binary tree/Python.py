from collections import deque
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Iterative function to print corner nodes of every level in a binary tree
def printTree(root):
 
    # return if the tree is empty
    if root is None:
        return
 
    # create an empty queue to store tree nodes
    q = deque()
 
    # enqueue root node
    q.append(root)
 
    # loop till queue is empty
    while q:
 
        # get the size of the current level
        size = len(q)
        n = size
 
        # process all nodes present in the current level
        while n:
            n = n - 1
            node = q.popleft()
 
            # if the corner node is found, print it
            if n == size - 1 or n == 0:
                print(node.data, end=' ')
 
            # enqueue left and right child of the current node
            if node.left:
                q.append(node.left)
 
            if node.right:
                q.append(node.right)
 
        # terminate level by printing an empty line
        print()
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
                 1
               /   \
              2     3
            /     /   \
           4     5     6
         /     /   \     \
        7     8     9     10
    '''
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.right.left = Node(5)
    root.right.right = Node(6)
    root.left.left.left = Node(7)
    root.right.left.left = Node(8)
    root.right.left.right = Node(9)
    root.right.right.right = Node(10)
 
    printTree(root)

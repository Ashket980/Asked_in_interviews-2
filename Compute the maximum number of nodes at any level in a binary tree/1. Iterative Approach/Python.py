from collections import deque
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, key=None, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right
 
 
# Function to find the maximum width of a binary tree using level order
# traversal of a given binary tree
def findMaxWidth(root):
 
    # return if the tree is empty
    if not root:
        return
 
    # create an empty queue and enqueue the root node
    queue = deque()
    queue.append(root)
 
    # stores the maximum width
    max = 0
 
    # loop till queue is empty
    while queue:
 
        # calculate the total number of nodes at the current level.
        # This is equal to the width of the current level.
        width = len(queue)
 
        # update maximum width if the total number of nodes at the current level
        # is more than the maximum width found so far
        if max < width:
            max = width
 
        # process every node of the current level and enqueue their
        # non-empty left and right child
        while width > 0:
            width = width - 1
            curr = queue.popleft()
 
            if curr.left:
                queue.append(curr.left)
 
            if curr.right:
                queue.append(curr.right)
 
    print('The maximum width is', max)
 
 
if __name__ == '__main__':
 
    root = Node(15)
    root.left = Node(10)
    root.right = Node(20)
    root.left.left = Node(8)
    root.left.right = Node(12)
    root.right.left = Node(16)
    root.right.right = Node(25)
 
    findMaxWidth(root)

from collections import deque
 
 
# Recursive function to find preorder traversal of a binary tree
# from its inorder and postorder sequence.
def printPreorder(start, end, postorder, pIndex, d, stack):
 
    # base case
    if start > end:
        return pIndex
 
    # The next element in the postorder sequence from the end will be the root node
    # of subtree formed by sequence inorder[start, end]
    value = postorder[pIndex]
    pIndex = pIndex - 1
 
    # get the current node index in inorder sequence to determine
    # its left and right subtree boundary
    index = d[value]
 
    # recur for the right subtree
    pIndex = printPreorder(index + 1, end, postorder, pIndex, d, stack)
 
    # recur for the left subtree
    pIndex = printPreorder(start, index - 1, postorder, pIndex, d, stack)
 
    # push the value of the current node into the stack
    stack.append(value)
 
    return pIndex
 
 
# Find preorder traversal of a binary tree from its inorder and
# postorder sequence. This function assumes that the input is valid.
# i.e., given inorder and postorder sequence forms a binary tree.
def findPreorder(inorder, postorder):
 
    # map is used to efficiently find the index of any element in
    # a given inorder sequence
    d = {}
 
    # fill the dictionary
    for i, e in enumerate(inorder):
        d[e] = i
 
    # `lastIndex` stores the index of the next unprocessed node from the end
    # of the postorder sequence
    lastIndex = len(inorder) - 1
 
    # construct a stack to store the preorder sequence
    stack = deque()
 
    # fill the stack
    printPreorder(0, lastIndex, postorder, lastIndex, d, stack)
 
    # print the stack
    print('The preorder traversal is ', end='')
    while stack:
        print(stack.pop(), end=' ')
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
               1
             /   \
            /     \
           2       3
          /       / \
         /       /   \
        4       5     6
               / \
              /   \
             7     8
    '''
 
    inorder = [4, 2, 1, 7, 5, 8, 3, 6]
    postorder = [4, 2, 7, 8, 5, 6, 3, 1]
 
    findPreorder(inorder, postorder)

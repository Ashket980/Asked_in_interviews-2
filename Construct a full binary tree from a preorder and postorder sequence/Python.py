# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Recursive function to perform inorder traversal on a given binary tree
def inorder(root):
 
    if root is None:
        return
 
    inorder(root.left)
    print(root.data, end=' ')
    inorder(root.right)
 
 
# A recursive function to construct a full binary tree from the given preorder
# and postorder sequence
def buildTree(preorder, pIndex, start, end, d):
 
    # Consider the next item from the given preorder sequence.
    # This item would be the root node of the subtree formed by
    # the `postorder[start, end]` and increment `pIndex`
    root = Node(preorder[pIndex])
    pIndex = pIndex + 1
 
    # return if all keys are processed
    if pIndex == len(preorder):
        return root, pIndex
 
    # find the next key index in the postorder sequence to determine the
    # boundary of the left and right subtree of the current root node
    index = d.get(preorder[pIndex])
 
    # fill the left and right subtree together
    if start <= index and index + 1 <= end - 1:
        # build the left subtree
        root.left, pIndex = buildTree(preorder, pIndex, start, index, d)
 
        # build the right subtree
        root.right, pIndex = buildTree(preorder, pIndex, index + 1, end - 1, d)
 
    return root, pIndex
 
 
# Construct a full binary tree from preorder and postorder sequence
def buildBinaryTree(preorder, postorder):
 
    # base case
    if not preorder:
        return
 
    # dictionary is used to efficiently find the index of any element in the given
    # postorder sequence
    d = {}
    for i, e in enumerate(postorder):
        d[e] = i
 
    # `pIndex` stores the index of the next node in the preorder sequence
    pIndex = 0
 
    # set range [start, end] for subtree formed by postorder sequence
    start = 0
    end = len(preorder) - 1
 
    # construct the binary tree and return it
    return buildTree(preorder, pIndex, start, end, d)[0]
 
 
if __name__ == '__main__':
 
    preorder = [1, 2, 4, 5, 3, 6, 8, 9, 7]
    postorder = [4, 5, 2, 8, 9, 6, 7, 3, 1]
 
    root = buildBinaryTree(preorder, postorder)
 
    print('Inorder traversal is ', end='')
    inorder(root)

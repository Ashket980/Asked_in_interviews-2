We can recursively check the above conditions. The idea is to search for the given node in the tree and 
update the predecessor to the current node before visiting its right subtree. If the node is found in the BST,
return the maximum value node in its left subtree. If the left subtree of the node doesn’t exist, 
then the inorder predecessor is one of its ancestors, which is already being updated while searching for the given key.

    Output:
 
    The predecessor of node 15 is 12
    The predecessor of node 10 is 8
    The predecessor of node 20 is 16
    The predecessor doesn’t exist for node 8
    The predecessor of node 12 is 10
    The predecessor of node 16 is 15
    The predecessor of node 25 is 20

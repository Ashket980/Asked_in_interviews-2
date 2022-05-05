## Build a binary tree from a parent array

**Given an integer array representing a binary tree, such that the parent-child relationship is defined by (A[i], i) 
for every index i in array A, build a binary tree out of it. The root node’s value is i if -1 is present at index i in the array. 
It may be assumed that the input provided to the program is valid.**

    For example,

    Parent: [-1, 0, 0, 1, 2, 2, 4, 4]
    
    Index : [ 0, 1, 2, 3, 4, 5, 6, 7]

    Note that,
    
    -1 is present at index 0, which implies that the binary tree root is node 0.
    
    0 is present at index 1 and 2, which implies that the left and right children of node 0 are 1 and 2.
    
    1 is present at index 3, which implies that the left or the right child of node 1 is 3.
    
    2 is present at index 4 and 5, which implies that the left and right children of node 2 are 4 and 5.
    
    4 is present at index 6 and 7, which implies that the left and right children of node 4 are 6 and 7.
    
The corresponding binary tree is:

![](https://www.techiedelight.com/wp-content/uploads/Build-Binary-Tree-from-Parent-Array.png)

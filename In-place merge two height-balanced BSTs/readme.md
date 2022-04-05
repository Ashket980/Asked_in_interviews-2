## In-place merge two height-balanced BSTs

**Given two height-balanced binary search trees, in-place merge them into a single balanced binary search tree.
For each node of a height-balanced tree, the difference between its left and right subtree height is at most 1.**

    For example,

    Input: Below BSTs
 
       20
      /  \
     10  30
       / \
      25 100
 
 
       50
      /  \
     5   70
 
    Output:
 
           30
          /    \
        20     70
       / \     / \
      10 25   50 100
     /
    5
 
    OR
 
           25
         /    \
        10     50
       /  \   /  \
      5   20 30  70
                   \
                   100

    OR

    Any other possible representation.

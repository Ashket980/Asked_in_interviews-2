// A class to store a binary tree node
class Node
{
    int data;
    Node left = null, right = null;
 
    Node(int data) {
        this.data = data;
    }
}
 
class Main
{
    // Helper function
    public static int findDiff(Node root, int diff, int level)
    {
        // base case
        if (root == null) {
            return diff;
        }
 
        // if the current level is odd
        if (level % 2 == 1) {
            diff = diff + root.data;
        }
        // if the current level is even
        else {
            diff = diff - root.data;
        }
 
        // recur for the left and right subtree
        diff = findDiff(root.left, diff, level + 1);
        diff = findDiff(root.right, diff, level + 1);
 
        return diff;
    }
 
    // Function to calculate the difference between the sum of all nodes present
    // at odd levels and the sum of all nodes present at even level
    public static int findDiff(Node root) {
        return findDiff(root, 0, 1);
    }
 
    public static void main(String[] args)
    {
        /* Construct the following tree
                  1
                /   \
               /     \
              2       3
             /      /  \
            /      /    \
           4      5      6
                 / \
                /   \
               7     8
        */
 
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.right.left = new Node(5);
        root.right.right = new Node(6);
        root.right.left.left = new Node(7);
        root.right.left.right = new Node(8);
 
        System.out.print(findDiff(root));
    }
}

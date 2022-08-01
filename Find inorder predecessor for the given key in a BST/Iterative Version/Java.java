// A class to store a BST node
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
    // Recursive function to insert a key into a BST
    public static Node insert(Node root, int key)
    {
        // if the root is null, create a new node and return it
        if (root == null) {
            return new Node(key);
        }
 
        // if the given key is less than the root node, recur for the left subtree
        if (key < root.data) {
            root.left = insert(root.left, key);
        }
 
        // if the given key is more than the root node, recur for the right subtree
        else {
            root.right = insert(root.right, key);
        }
 
        return root;
    }
 
    // Helper function to find the maximum value node in a given BST
    public static Node findMaximum(Node root)
    {
        while (root.right != null) {
            root = root.right;
        }
 
        return root;
    }
 
    // Iterative function to find inorder predecessor for a given key in the BST
    public static Node findPredecessor(Node root, int key)
    {
        // base case
        if (root == null) {
            return null;
        }
 
        Node prec = null;
 
        while (true)
        {
            // if the given key is less than the root node, visit the left subtree
            if (key < root.data) {
                root = root.left;
            }
 
            // if the given key is more than the root node, visit the right subtree
            else if (key > root.data)
            {
                // update predecessor to the current node before visiting
                // right subtree
                prec = root;
                root = root.right;
            }
 
            // if a node with the desired value is found, the predecessor is the
            // maximum value node in its left subtree (if any)
            else {
                if (root.left!= null) {
                    prec = findMaximum(root.left);
                }
                break;
            }
 
            // if the key doesn't exist in the binary tree,
            // return previous greater node
            if (root == null) {
                return prec;
            }
        }
 
        // return predecessor, if any
        return prec;
    }
 
    public static void main(String[] args)
    {
        int[] keys = { 15, 10, 20, 8, 12, 16, 25 };
 
        /* Construct the following tree
                   15
                 /    \
                /      \
               10       20
              /  \     /  \
             /    \   /    \
            8     12 16    25
        */
 
        Node root = null;
        for (int key: keys) {
            root = insert(root, key);
        }
 
        // find inorder predecessor for each key
        for (int key: keys)
        {
            Node prec = findPredecessor(root, key);
 
            if (prec != null)
            {
                System.out.println("The predecessor of node " + key + " is "
                                    + prec.data);
            }
            else {
                System.out.println("The predecessor doesn't exist for node " + key);
            }
        }
    }
}

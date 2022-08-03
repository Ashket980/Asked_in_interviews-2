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
    // Function to perform inorder traversal on the BST
    public static void inorder(Node root)
    {
        if (root == null) {
            return;
        }
 
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }
 
    // Helper function to find the maximum value node in the subtree rooted at `ptr`
    public static Node findMaximumKey(Node ptr)
    {
        while (ptr.right != null) {
            ptr = ptr.right;
        }
        return ptr;
    }
 
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
 
    // Function to delete a node from a BST
    public static Node deleteNode(Node root, int key)
    {
        // base case: the key is not found in the tree
        if (root == null) {
            return null;
        }
 
        // if the given key is less than the root node, recur for the left subtree
        if (key < root.data) {
            root.left = deleteNode(root.left, key);
        }
 
        // if the given key is more than the root node, recur for the right subtree
        else if (key > root.data) {
            root.right = deleteNode(root.right, key);
        }
 
        // key found
        else {
            // Case 1: node to be deleted has no children (it is a leaf node)
            if (root.left == null && root.right == null)
            {
                // update root to null
                return null;
            }
 
            // Case 2: node to be deleted has two children
            else if (root.left != null && root.right != null)
            {
                // find its inorder predecessor node
                Node predecessor = findMaximumKey(root.left);
 
                // copy value of the predecessor to the current node
                root.data = predecessor.data;
 
                // recursively delete the predecessor. Note that the
                // predecessor will have at most one child (left child)
                root.left = deleteNode(root.left, predecessor.data);
            }
 
            // Case 3: node to be deleted has only one child
            else {
                // choose a child node
                Node child = (root.left != null) ? root.left: root.right;
                root = child;
            }
        }
 
        return root;
    }
 
    public static void main(String[] args)
    {
        int[] keys = { 15, 10, 20, 8, 12, 25 };
 
        Node root = null;
        for (int key: keys) {
            root = insert(root, key);
        }
 
        root = deleteNode(root, 12);
        inorder(root);
    }
}

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
 
    // Function to perform inorder traversal on the given binary tree and
    // check if it is a BST or not. Here, `prev` is the previously processed node
    public static boolean isBST(Node root, Node prev)
    {
        // base case: empty tree is a BST
        if (root == null) {
            return true;
        }
 
        // check if the left subtree is BST or not
        boolean left = isBST(root.left, prev);
 
        // value of the current node should be more than that of the previous node
        if (root.data <= prev.data) {
            return false;
        }
 
        // update previous node data and check if the right subtree is BST or not
        prev.data = root.data;
 
        return left && isBST(root.right, prev);
    }
 
    // Function to determine whether a given binary tree is a BST
    public static void isBST(Node node)
    {
        // pointer to store previously processed node in the inorder traversal
        Node prev = new Node(Integer.MIN_VALUE);
 
        // check if nodes are processed in sorted order
        if (isBST(node, prev)) {
            System.out.println("The tree is a BST.");
        }
        else {
            System.out.println("The tree is not a BST!");
        }
    }
 
    private static void swap(Node root)
    {
        Node left = root.left;
        root.left = root.right;
        root.right = left;
    }
 
    public static void main(String[] args)
    {
        int[] keys = { 15, 10, 20, 8, 12, 16, 25 };
 
        Node root = null;
        for (int key: keys) {
            root = insert(root, key);
        }
 
        // swap nodes
        swap(root);
        isBST(root);
    }
}

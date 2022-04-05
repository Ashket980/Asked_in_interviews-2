import java.util.concurrent.atomic.AtomicInteger;
 
// A class to store a BST node
class Node
{
    int data;
    Node left, right;
 
    // Constructor
    Node(int data)
    {
        this.data = data;
        this.left = this.right = null;
    }
}
 
class Main
{
    // Wrapper over `Node` class
    static class NodeWrapper
    {
        public Node node;
 
        NodeWrapper(Node node) {
            this.node = node;
        }
    }
 
    // Helper function to perform the preorder traversal on a BST
    public static void preorder (Node root)
    {
        if (root == null) {
            return;
        }
 
        preorder(root.left);
        System.out.print(root.data + " ");
        preorder(root.right);
    }
 
    // Function to insert a BST node at the front of a doubly linked list
    public static Node push(Node root, Node head)
    {
        // insert the given node at the front of a DDL
        root.right = head;
 
        // update the left child of the existing head node of the DDL
        // to point to the BST node
        if (head != null) {
            head.left = root;
        }
 
        // update the head pointer of DDL
        head = root;
        return head;
    }
 
    /*
    Recursive function to construct a sorted doubly linked list from a BST
        root —> Pointer to the root node of the binary search tree
        head —> Reference to the head node of the doubly linked list
        nodes —> Stores the total number of nodes processed so far in the BST
    */
    public static Node convertBSTtoSortedDLL(Node root, Node head, AtomicInteger nodes)
    {
        // base case
        if (root == null) {
            return head;
        }
 
        // recursively convert the right subtree
        head = convertBSTtoSortedDLL(root.right, head, nodes);
 
        // push the current node at the front of the doubly linked list
        head = push(root, head);
 
        // increment the number of nodes
        nodes.incrementAndGet();
 
        // recursively convert the left subtree
        head = convertBSTtoSortedDLL(root.left, head, nodes);
 
        return head;
    }
 
    /*
    Recursive function to construct a height-balanced BST from a doubly linked list
        head —> Reference to the head node of the doubly linked list
        n    —> Total number of nodes in the doubly linked list
    */
    public static Node convertSortedDLLToBST(NodeWrapper head, int n)
    {
        // base case
        if (n <= 0) {
            return null;
        }
 
        // recursively construct the left subtree
        Node leftSubTree = convertSortedDLLToBST(head, n/2);
 
        // `head` now points to the middle node of the sorted DDL
 
        // make the middle node of the sorted DDL as the root node of the BST
        Node root = head.node;
 
        // update left child of the root node
        root.left = leftSubTree;
 
        // update the head reference of the doubly linked list
        head.node = head.node.right;
 
        // recursively construct the right subtree with the remaining nodes
        root.right = convertSortedDLLToBST(head, n - (n/2 + 1));
                                                /* +1 for the root node */
 
        // return the root node
        return root;
    }
 
    // Function to construct a height-balanced BST from an unbalanced BST
    public static Node constructBalancedBST(Node root)
    {
        // pointer to the head node of the doubly linked list
        Node head = null;
 
        /* Convert the given BST into a sorted doubly linked list and update the
            counter with the total number of nodes in the BST */
 
        // `AtomicInteger` is used here since `Integer` is passed by value in Java
        AtomicInteger nodes = new AtomicInteger(0);
 
        head = convertBSTtoSortedDLL(root, head, nodes);
 
        /* Construct a height-balanced BST from the sorted doubly linked list */
 
        // wrap the `head` node, so its reference can be changed inside the
        // `convertSortedDLLToBST()`
        root = convertSortedDLLToBST(new NodeWrapper(head), nodes.get());
 
        return root;
    }
 
    public static void main(String[] args)
    {
        Node root = new Node(20);
        root.left = new Node(15);
        root.left.left = new Node(10);
        root.left.left.left = new Node(5);
        root.left.left.left.left = new Node(2);
        root.left.left.left.right = new Node(8);
 
        root = constructBalancedBST(root);
 
        System.out.print("Preorder traversal of the constructed BST is ");
        preorder(root);
    }
}

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
    // Helper function to print a doubly linked list
    public static void printDoublyLinkedList(Node head)
    {
        while (head != null)
        {
            System.out.print(head.data + " —> ");
            head = head.right;
        }
        System.out.println("null");
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
 
    // Recursive function to convert a BST into a doubly-linked list. It takes
    // the BST's root node and the head node of the doubly linked list as an argument
    public static Node convertBSTtoDLL(Node root, Node head)
    {
        // Base case
        if (root == null) {
            return head;
        }
 
        // recursively convert the right subtree
        head = convertBSTtoDLL(root.right, head);
 
        // push the current node at the front of the doubly linked list
        head = push(root, head);
 
        // recursively convert the left subtree
        head = convertBSTtoDLL(root.left, head);
 
        return head;
    }
 
    // Recursive function to merge two doubly-linked lists into a
    // single doubly linked list in sorted order
    public static Node mergeDDLs(Node a, Node b)
    {
        // if the first list is empty, return the second list
        if (a == null) {
            return b;
        }
 
        // if the second list is empty, return the first list
        if (b == null) {
            return a;
        }
 
        // if the head node of the first list is smaller
        if (a.data < b.data)
        {
            a.right = mergeDDLs(a.right, b);
            a.right.left = a;
            return a;
        }
 
        // if the head node of the second list is smaller
        else {
            b.right = mergeDDLs(a, b.right);
            b.right.left = b;
            return b;
        }
    }
 
    // Function to merge two binary search trees into a doubly-linked list
    // in sorted order
    public static Node merge(Node a, Node b)
    {
        // convert the first binary search tree into a doubly-linked list
        Node first = null;
        first = convertBSTtoDLL(a, first);
 
        // convert the second binary search tree into a doubly-linked list
        Node second = null;
        second = convertBSTtoDLL(b, second);
 
        // merge both doubly-linked lists
        return mergeDDLs(first, second);
    }
 
    public static void main(String[] args)
    {
        /*
        Construct the first BST
              20
             /  \
            10  30
               /  \
              25  100
        */
 
        Node a = new Node(20);
        a.left = new Node(10);
        a.right = new Node(30);
        a.right.left = new Node(25);
        a.right.right = new Node(100);
 
        /*
        Construct the second BST
              50
             /  \
            5   70
        */
 
        Node b = new Node(50);
        b.left = new Node(5);
        b.right = new Node(70);
 
        // merge both BSTs into a doubly-linked list
        Node root = merge(a, b);
        printDoublyLinkedList(root);
    }
}

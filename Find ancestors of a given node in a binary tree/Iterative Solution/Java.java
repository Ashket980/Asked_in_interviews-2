import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;
 
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
    // Function to print root-to-leaf paths without using recursion
    public static void printTopToBottomPath(Map<Node, Node> parent, Node node)
    {
        while ((node = parent.get(node)) != null) {
            System.out.print(node.data + " ");
        }
    }
 
    // Iterative function to set parent nodes for all nodes of the binary tree
    // in a given map. The function is similar to the iterative preorder traversal
    public static void setParent(Node root, Map<Node, Node> parent)
    {
        // create an empty stack and push the root node
        Deque<Node> stack = new ArrayDeque<>();
        stack.add(root);
 
        // loop till stack is empty
        while (!stack.isEmpty())
        {
            // Pop the top item from the stack
            Node curr = stack.pollLast();
 
            // push its right child into the stack and set its parent on the map
            if (curr.right != null)
            {
                parent.put(curr.right, curr);
                stack.add(curr.right);
            }
 
            // push its left child into the stack and set its parent on the map
            if (curr.left != null)
            {
                parent.put(curr.left, curr);
                stack.add(curr.left);
            }
        }
    }
 
    // Iterative function to print all ancestors of a given node in a binary tree
    public static void printAncestors(Node root, Node node)
    {
        // base case
        if (root == null) {
            return;
        }
 
        // create an empty map to store parent pointers of binary tree nodes
        Map<Node, Node> parent = new HashMap<>();
 
        // set the parent of the root node as null
        parent.put(root, null);
 
        // set parent nodes for all nodes of the binary tree
        setParent(root, parent);
 
        // print ancestors of a given node using the parent map
        printTopToBottomPath(parent, node);
    }
 
    public static void main(String[] args)
    {
        /* Construct the following tree
                1
              /   \
             /     \
            2       3
             \     / \
              4   5   6
                 / \
                7   8
        */
 
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(4);
        root.right.left = new Node(5);
        root.right.right = new Node(6);
        root.right.left.left = new Node(7);
        root.right.left.right = new Node(8);
 
        Node node = root.right.left.left;    // Node 7
        printAncestors(root, node);
    }
}

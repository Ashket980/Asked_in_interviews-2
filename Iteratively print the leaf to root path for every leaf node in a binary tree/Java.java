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
    // Function to check if a given node is a leaf node or not
    public static boolean isLeaf(Node node) {
        return (node.left == null && node.right == null);
    }
 
    // Recursive function to print the root-to-leaf path for a given leaf
    public static void printPathRecursive(Node curr, Map<Node, Node> map)
    {
        // base case: `curr` is the root node (parent of the root node is null)
        if (curr == null) {
            return;
        }
 
        // recursively call the parent node
        printPathRecursive(map.get(curr), map);
        System.out.print(curr.data + (isLeaf(curr) ? "\n" : " —> "));
    }
 
    // Iterative function to print the leaf-to-root path for a given leaf.
    // For printing root-to-leaf path, we can use `printPathRecursive()` or a stack
    public static void printPathIterative(Node leafNode, Map<Node, Node> map)
    {
        // start from the leaf node
        Node curr = leafNode;
 
        // loop till the root node is reached and print each node in the path
        while (map.get(curr) != null)
        {
            System.out.print(curr.data + " —> ");
            curr = map.get(curr);
        }
 
        System.out.println(curr.data);
    }
 
    // Iterative function to print the leaf-to-root path for every leaf node
    public static void postorderIterative(Node root)
    {
        // base case
        if (root == null) {
            return;
        }
 
        // create an empty stack
        Deque<Node> stack = new ArrayDeque<>();
 
        // create an empty map to store (child, parent) pairs
        Map<Node, Node> map = new HashMap<>();
 
        // parent of the root node is null
        map.put(root, null);
 
        // push the root node
        stack.add(root);
 
        // loop till stack is empty
        while (!stack.isEmpty())
        {
            // pop the top node from the stack
            Node curr = stack.pollLast();
 
            // if a leaf node is found, print the path
            if (isLeaf(curr))
            {
                // print the leaf-to-root path for the current leaf
                printPathIterative(curr, map);
 
                // print root-to-leaf path for the current leaf
                // printPathRecursive(curr, map);
            }
 
            // Push the left and right child of the popped node into the stack.
            // Include the current node's left and right child on a map.
            if (curr.right != null)
            {
                stack.add(curr.right);
                map.put(curr.right, curr);
            }
 
            if (curr.left != null)
            {
                stack.add(curr.left);
                map.put(curr.left, curr);
            }
        }
    }
 
    public static void main(String[] args)
    {
        /* Construct the following tree
                    1
                  /   \
                 /     \
                /       \
               2         3
              / \       / \
             /   \     /   \
            4     5   6     7
                     / \
                    /   \
                   8     9
        */
 
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        root.right.left.left = new Node(8);
        root.right.left.right = new Node(9);
 
        postorderIterative(root);
    }
}

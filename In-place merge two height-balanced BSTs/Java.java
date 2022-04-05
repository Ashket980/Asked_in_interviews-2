import java.util.ArrayList;
import java.util.List;
 
// A BST node
class Node
{
    int data;
    Node left, right;
 
    Node(int data)
    {
        this.data = data;
        this.left = this.right = null;
    }
}
 
class Main
{
    // Function to print preorder traversal of the BST
    public static void preorder(Node root)
    {
        if (root == null) {
            return;
        }
 
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }
 
    // Function to store inorder traversal of a BST in a given list
    public static void inorder(Node root, List<Node> nodes)
    {
        if (root == null || nodes == null) {
            return;
        }
 
        inorder(root.left, nodes);
        nodes.add(root);
        inorder(root.right, nodes);
    }
 
    // Function to merge two sorted lists into a single sorted list
    public static List<Node> sortedMerge(List<Node> first, List<Node> second)
    {
        List<Node> result = new ArrayList<>();
 
        int i = 0, j = 0;
 
        while (i < first.size() && j < second.size())
        {
            // if the next node of the first list is smaller
            if (first.get(i).data < second.get(j).data) {
                result.add(first.get(i++));
            }
            // if the next node of the second list is smaller
            else {
                result.add(second.get(j++));
            }
        }
 
        // add any remaining nodes to the output list
 
        while (i < first.size()) {
            result.add(first.get(i++));
        }
 
        while (j < second.size()) {
            result.add(second.get(j++));
        }
 
        return result;
    }
 
    // Function to construct a balanced BST from a sorted list
    public static Node toBalancedBST(List<Node> nodes, int low, int high)
    {
        // base case
        if (low > high) {
            return null;
        }
 
        // find the middle of the current range
        int mid = (low + high) / 2;
 
        // `root` is the node corresponding to `mid`
        Node root = nodes.get(mid);
 
        // construct left subtree from nodes less than `mid`
        root.left = toBalancedBST(nodes, low, mid - 1);
 
        // construct the right subtree from nodes more than `mid`
        root.right = toBalancedBST(nodes, mid + 1, high);
 
        // return root node
        return root;
    }
 
    // Function to merge two balanced BSTs into a single balanced BST
    public static Node merge(Node a, Node b)
    {
        // store inorder traversal of the first BST in a list
        List<Node> first = new ArrayList<>();
        inorder(a, first);
 
        // store inorder traversal of the second BST in another list
        List<Node> second = new ArrayList<>();
        inorder(b, second);
 
        // merge both lists into a new sorted list
        List<Node> sortedNodes = sortedMerge(first, second);
 
        // construct and return the balanced BST from the sorted list
        return toBalancedBST(sortedNodes, 0, sortedNodes.size() - 1);
    }
 
    public static void main(String[] args)
    {
        /*
        Construct the first BST
              20
             /  \
            10  30
                / \
               25 100
        */
 
        Node first = new Node(20);
        first.left = new Node(10);
        first.right = new Node(30);
        first.right.left = new Node(25);
        first.right.right = new Node(100);
 
        /*
        Construct the second BST
              50
             /  \
            5    70
        */
 
        Node second = new Node(50);
        second.left = new Node(5);
        second.right = new Node(70);
 
        // merge both BSTs
        Node root = merge(first, second);
        preorder(root);
    }
}

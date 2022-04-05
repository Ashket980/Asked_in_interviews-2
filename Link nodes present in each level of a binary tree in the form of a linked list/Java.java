import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
 
// A class to store a binary tree node
class Node
{
    int data;
    Node left = null, right = null, next = null;
 
    Node(int data) {
        this.data = data;
    }
}
 
class Main
{
    // Function to print a given linked list
    public static void printList(Node head)
    {
        while (head != null)
        {
            System.out.print(head.data + " —> ");
            head = head.next;
        }
 
        System.out.println("null");
    }
 
    // Function to perform inorder traversal on a given binary tree where nodes
    // at the same level are linked together in the form of a linked list
    public static void inorder(Node root)
    {
        if (root == null) {
            return;
        }
 
        inorder(root.left);
 
        // print current node and its next node
        System.out.print(root.data + " —> ");
        if (root.next != null) {
            System.out.println(root.next.data);
        }
        else {
            System.out.println("null");
        }
 
        inorder(root.right);
    }
 
    // Recursive function to find the first node in the next level of a given root node
    public static Node findNextNode(Node root)
    {
        // base case
        if (root == null || root.next == null) {
            return null;
        }
 
        // if the left child of the root's next node exists, return it
        if (root.next.left != null) {
            return root.next.left;
        }
 
        // if the right child of the root's next node exists, return it
        if (root.next.right != null) {
            return root.next.right;
        }
 
        // if root's next node is a leaf node, recur for root's next node
        return findNextNode(root.next);
    }
 
    // Function to traverse the nodes in a preorder fashion and
    // insert all nodes into the map corresponding to their level
    public static void linkNodes(Node root, int level, Map<Integer, List<Node>> map)
    {
        // base case: empty subtree
        if (root == null) {
            return;
        }
 
        // insert the current node and level information into the map
        if (map.get(level) == null) {
            map.put(level, new ArrayList<>());
        }
        map.get(level).add(root);
 
        // recur for the left and right subtree by increasing the level by 1
        linkNodes(root.left, level + 1, map);
        linkNodes(root.right, level + 1, map);
    }
 
    // Function to link nodes present in each level of a binary tree
    // using the next pointer
    public static void linkNodes(Node root)
    {
        // create an empty map to store nodes present at each level
        // from left to right
        Map<Integer, List<Node>> map = new HashMap<>();
 
        // traverse the tree in a preorder fashion and fill the map
        linkNodes(root, 1, map);
 
        // iterate through the map, and for each level,
        // set the next node for every node in it
        for (List<Node> values: map.values())
        {
            Node prev = null;
            for (Node curr: values)
            {
                if (prev != null) {
                    prev.next = curr;
                }
                prev = curr;
            }
            prev.next = null;
        }
    }
 
    public static void main(String[] args)
    {
        /* Construct the following tree
                 1
               /   \
              2     3
             / \     \
            4   5     6
             \       /
              7     8
        */
 
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.right = new Node(6);
        root.left.left.right = new Node(7);
        root.right.right.left = new Node(8);
 
        // link nodes at the same level
        linkNodes(root);
 
        // print the nodes
        Node node = root;
        while (node != null)
        {
            // print the current level
            printList(node);
 
            // find the leftmost node in the next level
            if (node.left != null) {
                node = node.left;
            }
            else if (node.right != null) {
                node = node.right;
            }
            else {
                node = findNextNode(node);
            }
        }
 
        // inorder(root);
    }
}

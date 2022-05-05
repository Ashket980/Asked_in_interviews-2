import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
 
// A class to store a binary tree node
class Node
{
    int key;
    Node left = null, right = null;
 
    Node(int key) {
        this.key = key;
    }
}
 
class Main
{
    // Traverse the tree in a preorder fashion and store the count of nodes
    // in each level
    public static void preorder(Node root, int level, Map<Integer, Integer> map)
    {
        // base case: empty tree
        if (root == null) {
            return;
        }
 
        // increment count of nodes at the current level
        map.put(level, map.getOrDefault(level, 0) + 1);
 
        // recur for the left and right subtree by increasing the level by 1
        preorder(root.left, level + 1, map);
        preorder(root.right, level + 1, map);
    }
 
    // Recursive function to find the maximum width of a binary tree
    public static void findMaxWidth(Node root)
    {
        // base case
        if (root == null) {
            return;
        }
 
        // create an empty map to store the count of nodes in each level
        Map<Integer, Integer> map = new HashMap<>();
 
        // traverse the tree and fill the map
        preorder(root, 1, map);
 
        // iterate through the map and find maximum width
        int maxWidth = map.values().stream().max(Comparator.naturalOrder()).get();
        System.out.println("The maximum width is " + maxWidth);
    }
 
    public static void main(String[] args)
    {
        Node root = new Node(15);
        root.left = new Node(10);
        root.right = new Node(20);
        root.left.left = new Node(8);
        root.left.right = new Node(12);
        root.right.left = new Node(16);
        root.right.right = new Node(25);
 
        findMaxWidth(root);
    }
}

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
    // Function to perform inorder traversal on the tree
    public static void inorder(Node root)
    {
        if (root == null) {
            return;
        }
 
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }
 
    // Function to build a binary tree from the given parent array
    public static Node createTree(int[] parent)
    {
        // create an empty map
        Map<Integer, Node> map = new HashMap<>();
 
        // create `n` new tree nodes, each having a value from 0 to `n-1`,
        // and store them in a map
        for (int i = 0; i < parent.length; i++) {
            map.put(i, new Node(i));
        }
 
        // represents the root node of a binary tree
        Node root = null;
 
        // traverse the parent array and build the tree
        for (int i = 0; i < parent.length; i++)
        {
            // if the parent is -1, set the root to the current node having the
            // value `i` (stored in map[i])
            if (parent[i] == -1) {
                root = map.get(i);
            }
            else {
                // get the parent for the current node
                Node ptr = map.get(parent[i]);
 
                // if the parent's left child is filled, map the node to its right
                // child
                if (ptr.left != null) {
                    ptr.right = map.get(i);
                }
                // if the parent's left child is empty, map the node to it
                else {
                    ptr.left = map.get(i);
                }
            }
        }
 
        // return root of the constructed tree
        return root;
    }
 
    public static void main(String[] args)
    {
        int[] parent = {-1, 0, 0, 1, 2, 2, 4, 4};
 
        Node root = createTree(parent);
        inorder(root);
    }
}

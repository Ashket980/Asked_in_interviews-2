import java.util.ArrayDeque;
import java.util.Queue;
 
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
    // Function to find the maximum width of a binary tree using level order
    // traversal of a given binary tree
    public static void findMaxWidth(Node root)
    {
        // return if the tree is empty
        if (root == null) {
            return;
        }
 
        // create an empty queue and enqueue the root node
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(root);
 
        // to store the current node
        Node curr = null;
 
        // stores the maximum width
        int max = 0;
 
        // loop till queue is empty
        while (!queue.isEmpty())
        {
            // calculate the total number of nodes at the current level.
            // This is equal to the width of the current level.
            int width = queue.size();
 
            // update maximum width if the total number of nodes at the current level
            // is more than the maximum width found so far
            if (max < width) {
                max = width;
            }
 
            // process every node of the current level and enqueue their
            // non-empty left and right child
            while (width-- > 0)
            {
                curr = queue.poll();
 
                if (curr.left != null) {
                    queue.add(curr.left);
                }
 
                if (curr.right != null) {
                    queue.add(curr.right);
                }
            }
        }
 
        System.out.println("The maximum width is " + max);
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

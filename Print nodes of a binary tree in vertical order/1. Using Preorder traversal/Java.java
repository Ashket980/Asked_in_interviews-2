import java.util.ArrayList;
import java.util.List;
 
// Data structure to store a binary tree node
class TreeNode
{
    int data;
    TreeNode left, right;
 
    TreeNode(int data)
    {
        this.data = data;
        this.left = this.right = null;
    }
}
 
// A Doubly Linked List Node
class ListNode
{
    List<Integer> data = new ArrayList<>();
    ListNode prev, next;
 
    ListNode(ListNode prev, ListNode next)
    {
        this.prev = prev;
        this.next = next;
    }
}
 
class Main
{
    // Function to print the vertical order stored in a given doubly linked list
    public static void print(ListNode mid)
    {
        // find the head node
        while (mid != null && mid.prev != null) {
            mid = mid.prev;
        }
 
        // start with the head node
        ListNode head = mid;
        while (head != null)
        {
            System.out.println(head.data);
            head = head.next;
        }
    }
 
    // Recursive function to perform preorder traversal on the tree and determine
    // the vertical order of a given binary tree.
    // Each node of the doubly linked list will store nodes present at the
    // corresponding vertical line in a binary tree.
    public static void updateDLLwithVerticalOrder(TreeNode root, ListNode curr)
    {
        // base case
        if (root == null) {
            return;
        }
 
        // add the current tree node to the corresponding list node
        curr.data.add(root.data);
 
        // create a new linked list node corresponding to the vertical line passing
        // through the root's left child, if not already.
        // This node would become the `prev` pointer of the current list node
        if (root.left != null && curr.prev == null) {
            curr.prev = new ListNode(null, curr);
        }
 
        // create a new linked list node corresponding to the vertical line passing
        // through the root's right child, if not already.
        // This node would become the `next` pointer of the current list node
        if (root.right != null && curr.next == null) {
            curr.next = new ListNode(curr, null);
        }
 
        // recur for the left and right subtree
        updateDLLwithVerticalOrder(root.left, curr.prev);
        updateDLLwithVerticalOrder(root.right, curr.next);
    }
 
    // Function to print nodes of a given binary tree in vertical order
    public static void printVertical(TreeNode root)
    {
        // create a new linked list node corresponding to the vertical line passing
        // through the root node
        ListNode curr = new ListNode(null, null);
 
        // determine the vertical order and store it in a doubly-linked list
        updateDLLwithVerticalOrder(root, curr);
 
        // print the linked list
        print(curr);
    }
 
    public static void main(String[] args)
    {
        /* Construct the following tree
                  1
                /   \
               /     \
              2       3
                    /   \
                   /     \
                  5       6
                /   \
               /     \
              7       8
                    /   \
                   /     \
                  9      10
        */
 
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.right.left = new TreeNode(5);
        root.right.right = new TreeNode(6);
        root.right.left.left = new TreeNode(7);
        root.right.left.right = new TreeNode(8);
        root.right.left.right.left = new TreeNode(9);
        root.right.left.right.right = new TreeNode(10);
 
        printVertical(root);
    }
}

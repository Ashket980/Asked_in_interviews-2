import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
 
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
 
// A Pair class
class Pair<U, V>
{
    public final U first;       // first field of a pair
    public final V second;      // second field of a pair
 
    // Constructs a new Pair with specified values
    private Pair(U first, V second)
    {
        this.first = first;
        this.second = second;
    }
 
    // Factory method for creating a Typed Pair immutable instance
    public static <U, V> Pair <U, V> of(U a, V b)
    {
        // calls private constructor
        return new Pair<>(a, b);
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
 
    // Function to perform level order traversal on the tree and determine
    // the vertical order of a given binary tree.
    // Each node of the doubly linked list will store nodes present at the
    // corresponding vertical line in a binary tree.
    public static void updateDLLwithVerticalOrder(TreeNode root, ListNode curr)
    {
        // base case
        if (root == null) {
            return;
        }
 
        // create an empty queue for level order traversal and
        // enqueue root node with its corresponding linked list node
        Queue<Pair<TreeNode, ListNode>> q = new ArrayDeque<>();
        q.add(Pair.of(root, curr));
 
        // loop till queue is empty
        while (!q.isEmpty())
        {
            // dequeue front node
            TreeNode node = q.peek().first;     // tree node
            curr = q.peek().second;             // list node
            q.poll();
 
            // push the value of the current tree node into the corresponding list node
            curr.data.add(node.data);
 
            // process non-empty left child
            if (node.left != null)
            {
                // create a new linked list node corresponding to the vertical line
                // passing through the node's left child, if not already.
                // This node would become the `prev` pointer of the current list node
                if (curr.prev == null) {
                    curr.prev = new ListNode(null, curr);
                }
 
                // enqueue left child with its corresponding linked list node
                q.add(Pair.of(node.left, curr.prev));
            }
 
            // process non-empty right child
            if (node.right != null)
            {
                // create a new linked list node corresponding to the vertical line
                // passing through the node's right child, if not already.
                // This node would become the `next` pointer of the current list node
                if (curr.next == null) {
                    curr.next = new ListNode(curr, null);
                }
 
                // enqueue right child with its corresponding linked list node
                q.add(Pair.of(node.right, curr.next));
            }
        }
    }
 
    // Function to print nodes of a given binary tree in vertical order
    public static void printVertical(TreeNode root)
    {
        // create a new linked list node corresponding to the vertical line passing
        // through the root node
        ListNode curr = new ListNode(null, null);
 
        // determine vertical order and store it in a doubly-linked list
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

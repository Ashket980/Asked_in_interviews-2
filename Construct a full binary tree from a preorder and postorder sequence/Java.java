import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;
 
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
    // Recursive function to perform inorder traversal on a given binary tree
    public static void inorder(Node root)
    {
        if (root == null) {
            return;
        }
 
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }
 
    // A recursive function to construct a full binary tree from the given preorder
    // and postorder sequence
    public static Node buildTree(int[] preorder, AtomicInteger pIndex,
                                int start, int end, Map<Integer, Integer> map)
    {
        // Consider the next item from the given preorder sequence.
        // This item would be the root node of the subtree formed by
        // the `postorder[start, end]` and increment `pIndex`
        Node root = new Node(preorder[pIndex.getAndIncrement()]);
 
        // return if all keys are processed
        if (pIndex.get() == preorder.length) {
            return root;
        }
 
        // find the next key index in the postorder sequence to determine the
        // boundary of the left and right subtree of the current root node
        int index = map.get(preorder[pIndex.get()]);
 
        // fill the left and right subtree together
        if (start <= index && index + 1 <= end - 1)
        {
            // build the left subtree
            root.left = buildTree(preorder, pIndex, start, index, map);
 
            // build the right subtree
            root.right = buildTree(preorder, pIndex, index + 1, end - 1, map);
        }
 
        return root;
    }
 
    // Construct a full binary tree from preorder and postorder sequence
    public static Node buildTree(int[] preorder, int[] postorder)
    {
        // base case
        if (postorder.length == 0) {
            return null;
        }
 
        // map is used to efficiently find the index of any element in the given
        // postorder sequence
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < postorder.length; i++) {
            map.put(postorder[i], i);
        }
 
        // `pIndex` stores the index of the next node in the preorder sequence
        AtomicInteger pIndex = new AtomicInteger(0);
 
        // set range [start, end] for subtree formed by postorder sequence
        int start = 0;
        int end = preorder.length - 1;
 
        // construct the binary tree and return it
        return buildTree(preorder, pIndex, start, end, map);
    }
 
    public static void main(String[] args)
    {
        int[] preorder = { 1, 2, 4, 5, 3, 6, 8, 9, 7 };
        int[] postorder = { 4, 5, 2, 8, 9, 6, 7, 3, 1 };
 
        Node root = buildTree(preorder, postorder);
 
        System.out.print("Inorder traversal is ");
        inorder(root);
    }
}

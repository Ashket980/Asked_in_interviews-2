import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;
 
class Main
{
    // Recursive function to find preorder traversal of a binary tree
    // from its inorder and postorder sequence.
    public static int printPreorder(int start, int end, int[] postorder, int pIndex,
                                    Map<Integer, Integer> map, Deque<Integer> stack)
    {
        // base case
        if (start > end) {
            return pIndex;
        }
 
        // The next element in the postorder sequence from the end will be the
        // root node of subtree formed by sequence inorder[start, end]
        int value = postorder[pIndex--];
 
        // get the current node index in inorder sequence to determine
        // its left and right subtree boundary
        int index = map.get(value);
 
        // recur for the right subtree
        pIndex = printPreorder(index + 1, end, postorder, pIndex, map, stack);
 
        // recur for the left subtree
        pIndex = printPreorder(start, index - 1, postorder, pIndex, map, stack);
 
        // push the value of the current node into the stack
        stack.push(value);
 
        return pIndex;
    }
 
    // Find preorder traversal of a binary tree from its inorder and
    // postorder sequence. This function assumes that the input is valid.
    // i.e., given inorder and postorder sequence forms a binary tree.
    public static void findPreorder(int[] inorder, int[] postorder)
    {
        // map is used to efficiently find the index of any element in
        // a given inorder sequence
        Map<Integer, Integer> map = new HashMap<>();
 
        // fill the map
        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
 
        // `lastIndex` stores the index of the next unprocessed node from the end
        // of the postorder sequence
        int lastIndex = inorder.length - 1;
 
        // construct a stack to store the preorder sequence
        Deque<Integer> stack = new ArrayDeque<>();
 
        // fill the stack
        printPreorder(0, lastIndex, postorder, lastIndex, map, stack);
 
        // print the stack
        System.out.print("The preorder traversal is ");
        while (!stack.isEmpty()) {
            System.out.print(stack.poll() + " ");
        }
    }
 
    public static void main(String[] args)
    {
        /* Construct the following tree
                   1
                 /   \
                /     \
               2       3
              /       / \
             /       /   \
            4       5     6
                   / \
                  /   \
                 7     8
        */
 
        int[] inorder    = { 4, 2, 1, 7, 5, 8, 3, 6 };
        int[] postorder = { 4, 2, 7, 8, 5, 6, 3, 1 };
 
        findPreorder(inorder, postorder);
    }
}

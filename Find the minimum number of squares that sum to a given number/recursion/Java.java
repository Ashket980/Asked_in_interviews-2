class Main
{
    // Utility function to check if a given number `n` is a perfect square or not
    public static boolean isPerfectSquare(int n)
    {
        // find the floating-point value of the square root of `n`
        double sqr = Math.sqrt(n);
 
        // return true if the square root is an integer
        return sqr == Math.floor(sqr);
    }
 
    // Recursive function to find the minimum number of squares that sum to `n`
    public static int findMinSquares(int n)
    {
        // base case: `n` is a perfect square
        if (isPerfectSquare(n)) {
            return 1;
        }
 
        // initialize the result with the maximum number of squares possible
        int result = n;
 
        // loop through all positive integers less than the square root of `n`
        for (int i = 1; i*i < n; i++)
        {
            // recur for `n-i×i` and update the result if a lesser value is found
            result = Integer.min(result, 1 + findMinSquares(n - i*i));
        }
 
        return result;
    }
 
    public static void main(String[] args)
    {
        int n = 63;
        System.out.println("The minimum number of squares is " + findMinSquares(n));
    }
}

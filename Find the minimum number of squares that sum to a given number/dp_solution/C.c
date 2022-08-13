#include <stdio.h>
 
// Utility function to find the minimum among two integers `x` and `y`
int min(int x, int y) {
    return x < y ? x : y;
}
 
// Iterative function to find the minimum number of squares that sum to `n`
int findMinSquares(int n)
{
    // create an auxiliary array T[], where T[i] stores the minimum number
    // of squares that sum to `i`
    int T[n + 1];
 
    // fill the auxiliary array T[] in a bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        // initialize T[i] with the maximum number of squares possible
        T[i] = i;
 
        // loop through all positive integers less than or equal to the
        // square root of `i`
        for (int j = 1; j*j <= i; j++)
        {
            // calculate the value of T[i] using the result of a smaller
            // subproblem T[i-j×j]
            T[i] = min(T[i], 1 + T[i - j*j]);
        }
    }
 
    return T[n];
}
 
int main(void)
{
    int n = 63;
    printf("The minimum number of squares is %d", findMinSquares(n));
 
    return 0;
}

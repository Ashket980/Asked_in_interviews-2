#include <iostream>
#include <cmath>
using namespace std;
 
// Utility function to check if a given number `n` is a perfect square or not
bool isPerfectSquare(int n)
{
    // find the floating-point value of the square root of `n`
    long double sqr = sqrt(n);
 
    // return true if the square root is an integer
    return sqr == floor(sqr);
}
 
// Recursive function to find the minimum number of squares that sum to `n`
int findMinSquares(int n)
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
        result = min(result, 1 + findMinSquares(n - i*i));
    }
 
    return result;
}
 
int main()
{
    int n = 63;
    cout << "The minimum number of squares is " << findMinSquares(n) << endl;
 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
 
// Recursive function to check if `X[0…n)` and `Y[0…n)`
// represent the same BSTs or not
int isSameBST(int X[], int Y[], int n)
{
    // if no element is present in the array, return true
    if (n == 0) {
        return 1;
    }
 
    // if the first element differs in both array (root node key),
    // return false
    if (X[0] != Y[0]) {
        return 0;
    }
 
    // if the array contains only one key, return true
    if (n == 1) {
        return 1;
    }
 
    // take four auxiliary arrays of size `n-1` each (as maximum
    // keys in left or right subtree can be `n-1`)
    int leftX[n-1], rightX[n-1], leftY[n-1], rightY[n-1];
 
    int k = 0, l = 0, m = 0, o = 0;
 
    // process the remaining keys and divide them into two groups
    for (int i = 1; i < n; i++)
    {
        // `leftX[]` will contain all elements less than `X[0]`
        if (X[i] < X[0]) {
            leftX[k++] = X[i];
        }
        // `rightX[]` will contain all elements more than `X[0]`
        else {
            rightX[l++] = X[i];
        }
 
        // `leftY[]` will contain all elements less than `Y[0]`
        if (Y[i] < Y[0]) {
            leftY[m++] = Y[i];
        }
        // `rightY[]` will contain all elements more than `Y[0]`
        else {
            rightY[o++] = Y[i];
        }
    }
 
    // return false if the size of `leftX[]` and `leftY[]` differs, i.e.,
    // the total number of nodes in the left subtree of both trees differs
    if (k != m) {
        return 0;
    }
 
    // return false if the size of `rightX[]` and `rightY[]` differs, i.e.,
    // the total number of nodes in the right subtree of both trees differs
    if (l != o) {
        return 0;
    }
 
    // check left and right subtree
    return isSameBST(leftX, leftY, k) && isSameBST(rightX, rightY, l);
}
 
int main(void)
{
    int X[] = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
    int Y[] = { 15, 10, 12, 8, 25, 30, 6, 20, 18, 9, 22 };
 
    int n = sizeof(X) / sizeof(X[0]);
    int m = sizeof(Y) / sizeof(Y[0]);
 
    if (m == n && isSameBST(X, Y, n)) {
        printf("Given keys represent the same BSTs");
    }
    else {
        printf("Given keys represent different BSTs");
    }
 
    return 0;
}

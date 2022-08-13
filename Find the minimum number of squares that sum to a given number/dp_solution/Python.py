# Iterative function to find the minimum number of squares that sum to `n`
def findMinSquares(n):
 
    # create an auxiliary array T[], where T[i] stores the minimum number
    # of squares that sum to `i`
    T = [0] * (n + 1)
 
    # fill the auxiliary array T[] in a bottom-up manner
    for i in range(n + 1):
 
        # initialize T[i] with the maximum number of squares possible
        T[i] = i
 
        # loop through all positive integers less than or equal to the
        # square root of `i`
        j = 1
        while j*j <= i:
            # calculate the value of T[i] using the result of a smaller
            # subproblem T[i-j×j]
            T[i] = min(T[i], 1 + T[i - j*j])
            j += 1
 
    return T[n]
 
 
if __name__ == '__main__':
 
    n = 63
    print('The minimum number of squares is', findMinSquares(n))

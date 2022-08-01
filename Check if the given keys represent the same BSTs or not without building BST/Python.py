# Recursive function to check if `X[0…n)` and `Y[0…n)` represent the same BSTs or not
def isSameBST(X, Y, n):
 
    # if no element is present in the list, return true
    if n == 0:
        return True
 
    # if the first element differs in both lists (root node key), return false
    if X[0] != Y[0]:
        return False
 
    # if the list contains only one key, return true
    if n == 1:
        return True
 
    # take four auxiliary spaces of size `n-1` each (as maximum keys in
    # left or right subtree can be `n-1`)
    leftX = [None] * (n - 1)
    rightX = [None] * (n - 1)
    leftY = [None] * (n - 1)
    rightY = [None] * (n - 1)
 
    k = l = m = o = 0
 
    # process the remaining keys and divide them into two groups
    for i in range(1, n):
 
        # `leftX` will contain all elements less than `X[0]`
        if X[i] < X[0]:
            leftX[k] = X[i]
            k = k + 1
 
        # `rightX` will contain all elements more than `X[0]`
        else:
            rightX[l] = X[i]
            l = l + 1
 
        # `leftY` will contain all elements less than `Y[0]`
        if Y[i] < Y[0]:
            leftY[m] = Y[i]
            m = m + 1
 
        # `rightY` will contain all elements more than `Y[0]`
        else:
            rightY[o] = Y[i]
            o = o + 1
 
    # return false if the size of `leftX` and `leftY` differs, i.e.,
    # the total number of nodes in the left subtree of both trees differs
    if k != m:
        return False
 
    # return false if the size of `rightX` and `rightY` differs, i.e.,
    # the total number of nodes in the right subtree of both trees differs
    if l != o:
        return False
 
    # check left and right subtree
    return isSameBST(leftX, leftY, k) and isSameBST(rightX, rightY, l)
 
 
if __name__ == '__main__':
 
    X = [15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6]
    Y = [15, 10, 12, 8, 25, 30, 6, 20, 18, 9, 22]
 
    if len(X) == len(Y) and isSameBST(X, Y, len(X)):
        print('Given keys represent the same BSTs')
    else:
        print('Given keys represent different BSTs')

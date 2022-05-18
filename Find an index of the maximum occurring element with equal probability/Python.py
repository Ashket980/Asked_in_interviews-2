from random import randint
 
 
# Return the index of the maximum occurring element with equal probability
def findIndex(nums):
 
    # store count of each list element in a dictionary
    count = {}
    for i in nums:
        count[i] = count.get(i, 0) + 1
 
    # traverse the array and find the first maximum occurring element
    max_occurring = nums[0]
    for i in nums:
        if count[max_occurring] < count[i]:
            max_occurring = i
 
    # generate a random number `k` between 1 and count of the maximum occurring element
    k = randint(1, count[max_occurring])
 
    # traverse the input list and return the index of the k'th occurrence
    # of the maximum occurring element
    index = 0
    while k and index < len(nums):
        if nums[index] == max_occurring:
            k = k - 1
        index = index + 1
 
    return index - 1
 
 
if __name__ == '__main__':
 
    nums = [4, 3, 6, 8, 4, 6, 2, 4, 5, 9, 7, 4]
 
    for i in range(5):
        print('The index of the maximum occurring element is', findIndex(nums))
 

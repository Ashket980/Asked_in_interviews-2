#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <unistd.h>        // for `sleep()`
using namespace std;
 
// Return the index of the maximum occurring element with equal probability
int findIndex(vector<int> const &nums)
{
    // store count of each input element in an `unordered_map`
    unordered_map<int, int> count;
    for (int i: nums) {
        count[i]++;
    }
 
    // traverse the array and find the first maximum occurring element
    int max_occurring = nums[0];
    for (int i: nums)
    {
        if (count[max_occurring] < count[i]) {
            max_occurring = i;
        }
    }
 
    // initialize the srand with a distinctive value and generate a random
    // number `k` between 1 and count of the maximum occurring element
    srand(time(nullptr));
    int k = (rand() % count[max_occurring]) + 1;
 
    // traverse the input vector and return the index of the k'th occurrence
    // of the maximum occurring element
    int index = 0;
    while (k && index < nums.size())
    {
        if (nums[index] == max_occurring) {
            k--;
        }
 
        index++;
    }
 
    return index - 1;
}
 
int main()
{
    vector<int> nums = { 4, 3, 6, 8, 4, 6, 2, 4, 5, 9, 7, 4 };
 
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        cout << "The index of the maximum occurring element is "
             << findIndex(nums) << endl;
    }
 
    return 0;
}

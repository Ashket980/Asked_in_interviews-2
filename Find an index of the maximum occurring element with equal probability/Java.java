import java.util.*;
 
class Main
{
    public static int rand(int min, int max)
    {
        if (min > max || (max - min + 1 > Integer.MAX_VALUE)) {
            throw new IllegalArgumentException("Invalid range");
        }
        return new Random().nextInt(max - min + 1) + min;
    }
 
    // Return the index of the maximum occurring element with equal probability
    public static int findIndex(int[] nums)
    {
        // store count of each list element in a `HashMap`
        Map<Integer, Integer> count = new HashMap<>();
        for (int i: nums) {
            count.put(i, count.getOrDefault(i, 0) + 1);
        }
 
        // traverse the array and find the first maximum occurring element
        int max_occurring = nums[0];
        for (int i: nums)
        {
            if (count.get(max_occurring) < count.get(i)) {
                max_occurring = i;
            }
        }
 
        // generate a random number `k` between 1 and count of the
        // maximum occurring element
        int k = rand(1, count.get(max_occurring));
 
        // traverse the input list and return the index of the k'th
        // occurrence of the maximum occurring element
        int index = 0;
        while (k != 0 && index < nums.length)
        {
            if (nums[index] == max_occurring) {
                k--;
            }
            index++;
        }
 
        return index - 1;
    }
 
    public static void main(String[] args)
    {
        int[] nums = {4, 3, 6, 8, 4, 6, 2, 4, 5, 9, 7, 4};
 
        for (int i = 0; i < 5; i++)
        {
            System.out.println("The index of the maximum occurring element is "
                    + findIndex(nums));
        }
    }
}

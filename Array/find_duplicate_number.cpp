#include<iostream>
using namespace std;

// FIND THE DUPLICATE NUMBER (LEETCODE 287)
// MARKING VISITED VALUE - TC=O(N), SC=O(1)

// Steps:
// 1. Iterate through each number in the array.
// 2. For each number, get the absolute value and use it as an index.
// 3. Check if the value at this index is negative. If yes, a duplicate is found.
// 4. If no, mark the value at this index as visited by making it negative.
// 5. Return the duplicate number once found.

int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    for (int num : nums)
    {
        int index = abs(num);
        if (nums[index] < 0)
        {
            return index;
        }
        nums[index] = -nums[index];
    }
    return -1;
}
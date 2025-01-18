#include<iostream>
using namespace std;

// K-DIFF PAIRS IN AN ARRAY (LEETCODE 532)
// USING SET AND TWO POINTERS APPROACH - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Sort the array to facilitate the two-pointer technique.
// 2. Initialize a set to store unique pairs and two pointers, `i` and `j`.
// 3. Traverse the array using two pointers to find pairs with the difference `k`.
// 4. If the difference is `k`, add the pair to the set and increment both pointers.
// 5. If the difference is greater than `k`, increment `i` to reduce the difference.
// 6. If the difference is less than `k`, increment `j` to increase the difference.
// 7. Ensure `i` and `j` are distinct by incrementing `j` if they are equal.
// 8. Return the size of the set, representing the number of unique pairs.

int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int n = nums.size();
    int i = 0;
    int j = 1;
    while (j < n)
    {
        int value = nums[j] - nums[i];
        if (value == k)
        {
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if (value > k)
        {
            i++;
        }
        else
        {
            j++;
        }
        if (i == j)
        {
            j++;
        }
    }
    return ans.size();
}
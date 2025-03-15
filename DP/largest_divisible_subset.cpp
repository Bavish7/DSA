#include<iostream>
using namespace std;

// LARGEST DIVISIBLE SUBSET (LEETCODE 368)
// USING SORTING AND LIS - TC=O(N^2), SC=O(N)

// Steps:
// 1. Sort the input array to ensure that divisibility checks work efficiently.
// 2. Use dynamic programming with two arrays:
//    a. `curr[i]`: Stores the length of the largest divisible subset ending at nums[i].
//    b. `prev[i]`: Stores the index of the previous element in the subset ending at nums[i].
// 3. For each pair (i, j) where j < i:
//    a. Check if nums[i] is divisible by nums[j].
//    b. If true and adding nums[i] to the subset ending at nums[j] increases the subset length, update curr[i] and prev[i].
// 4. Keep track of the index with the largest subset length.
// 5. Backtrack using the `prev` array to construct the result subset.

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int index = 0;
    int n = nums.size();
    vector<int> curr(n, 1), prev(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && curr[i] < curr[j] + 1)
            {
                curr[i] = curr[j] + 1;
                prev[i] = j;
            }
        }
        if (curr[i] > curr[index])
            index = i;
    }
    vector<int> ans;
    while (index >= 0)
    {
        ans.push_back(nums[index]);
        index = prev[index];
    }
    return ans;
}
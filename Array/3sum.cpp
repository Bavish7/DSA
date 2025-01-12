#include<iostream>
using namespace std;

// 3SUM (LEETCODE 15)
// USING SORTING AND TWO POINTERS - TC=O(N^2), SC=O(1)

// Steps:
// 1. Sort the input array to facilitate two-pointer traversal and avoid duplicates.
// 2. Iterate through the array, treating each element as a potential first element of a triplet.
// 3. For each first element, use a two-pointer approach (j, k) to find pairs that sum to the negative of the first element.
// 4. If the triplet sum is less than 0, move the left pointer (j) forward to increase the sum.
// 5. If the triplet sum is greater than 0, move the right pointer (k) backward to decrease the sum.
// 6. When a valid triplet is found, add it to the result and adjust pointers to skip duplicate values.
// 7. Return the list of all unique triplets after processing the entire array.

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return ans;
}
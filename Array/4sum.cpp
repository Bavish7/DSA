#include<iostream>
using namespace std;

// 4SUM (LEETCODE 18)
// USING SORTING AND TWO POINTERS - TC=O(N^3), SC=O(1)

// Steps:
// 1. Sort the input array to facilitate the use of a two-pointer approach and handle duplicates.
// 2. Use two nested loops to fix the first two elements of a potential quadruplet.
// 3. For the remaining two elements, use a two-pointer approach (k, l) to find pairs that sum up to the required value to reach the target.
// 4. If the current sum is less than the target, move the left pointer (k) forward to increase the sum.
// 5. If the current sum is greater than the target, move the right pointer (l) backward to decrease the sum.
// 6. When a valid quadruplet is found, add it to the result and adjust pointers to skip duplicate values for both k and l.
// 7. Skip duplicate values for the first two elements in the nested loops to avoid redundant quadruplets.
// 8. Return the list of all unique quadruplets after processing the entire array.

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum > target)
                {
                    l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
            }
        }
    }
    return ans;
}
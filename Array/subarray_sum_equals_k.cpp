#include<iostream>
using namespace std;

// SUBARRAY SUM EQUALS K (LEETCODE 560)
// USING UNORDERED MAP AND PREFIX SUM - TC=O(N), SC=O(N)

// Steps:
// 1. Maintain a prefix sum as you traverse the array.
// 2. Use a hashmap to store the count of prefix sums encountered so far.
// 3. For each element, check if `prefixSum - k` exists in the hashmap:
//    - If it exists, the difference indicates that there exists a subarray ending at the current index whose sum is `k`.
// 4. Increment the count of the current prefix sum in the hashmap.

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int prefixSum = 0, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        int rem = prefixSum - k;
        count += mp[rem];
        mp[prefixSum] += 1;
    }
    return count;
}
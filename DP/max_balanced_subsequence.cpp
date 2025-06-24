#include<iostream>
using namespace std;

// MAXIMUM BALANCED SUBSEQUENCE SUM (LEETCODE 2926)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Define `prev` and `curr` indices to track subsequence progress.
// 2. Use memoization with a unique string key `"prev_curr"` to store intermediate results.
// 3. Base case: when `curr` reaches the end of the array, return 0.
// 4. Include current element if valid: `nums[curr] - curr >= nums[prev] - prev`.
//    - Add nums[curr] and recurse with updated `prev = curr`.
// 5. Exclude current element and move to next index.
// 6. Store and return the max of including or excluding the current element.
// 7. Edge case: if all elements are non-positive, return the largest single value.

unordered_map<string, long long> mp;
long long solveUsingMem(int prev, int curr, vector<int> &nums)
{
    if (curr == nums.size())
        return 0;
    string key = to_string(prev) + "_" + to_string(curr);
    if (mp.find(key) != mp.end())
        return mp[key];
    long long include = 0;
    if (prev == -1 || nums[curr] - curr >= nums[prev] - prev)
    {
        include = nums[curr] + solveUsingMem(curr, curr + 1, nums);
    }
    long long exclude = solveUsingMem(prev, curr + 1, nums);
    return mp[key] = max<long long>(include, exclude);
}
long long maxBalancedSubsequenceSum(vector<int> &nums)
{
    int n = nums.size();
    int maxEle = *max_element(nums.begin(), nums.end());
    if (maxEle <= 0)
        return maxEle;
    return solveUsingMem(-1, 0, nums);
}

// USING OPTIMAL LIS APPORACH - TC=O(N*LOGN), SC=O(N)
// Steps:
// 1. For each element at index `i`, calculate key as `nums[i] - i`.
// 2. Use a map to store the max subsequence sum ending at keys (nums[i] - i).
// 3. For current index, find max sum from any previous key less than current key.
// 4. Add nums[i] to that sum and update current key’s value if it’s better.
// 5. Clean up the map by erasing all future keys with smaller or equal sums to maintain optimal state.
// 6. Track the overall maximum sum across all valid states.

long long maxBalancedSubsequenceSum(vector<int>& nums) {
    int n=nums.size();
    map<int,long long>mp;
    long long ans=INT_MIN;
    for(int i=0;i<n;i++){
        auto it=mp.upper_bound(nums[i]-i);
        long long sum=nums[i];
        if(it!=mp.begin()){
            it--;
            sum+=it->second;
        }
        mp[nums[i]-i]=max(mp[nums[i]-i],sum);
        it=mp.upper_bound(nums[i]-i);
        while(it!=mp.end() && it->second<=sum){
            mp.erase(it++);
        }
        ans=max(ans,sum);
    }
    return ans;
}

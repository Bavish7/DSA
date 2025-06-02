#include<iostream>
using namespace std;

// SUBARRAYS WITH K DIFFERENT INTEGERS (LEETCODE 992)
// USING VARIABLE SIZE WINDOW - TC=O(4N), SC=O(2N)

// Steps:
// 1. Define `atMostK` to count subarrays with at most `k` distinct integers:
//    - Maintain a sliding window `[l, r]` and a hash map `mp` for frequency of elements in the window.
//    - Add the right element `nums[r]` to the map and increment its frequency.
//    - If the map size exceeds `k`, shrink the window from the left until the condition is met by decrementing `mp[nums[l]]` and removing elements with zero frequency.
//    - Add `(r - l + 1)` valid subarrays to the count.
// 2. Use the formula `atMostK(nums, k) - atMostK(nums, k - 1)` to compute the number of subarrays with exactly `k` distinct integers by taking the difference between subarrays with at most `k` and at most `k-1` distinct integers.
// 3. Return the result from `subarraysWithKDistinct`.

int atMostK(vector<int> &nums, int k)
{
    int l = 0, r = 0, count = 0;
    unordered_map<int, int> mp;
    while (r < nums.size())
    {
        mp[nums[r]]++;
        while (mp.size() > k)
        {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
            {
                mp.erase(nums[l]);
            }
            l++;
        }
        count += r - l + 1;
        r++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return atMostK(nums, k) - atMostK(nums, k - 1);
}



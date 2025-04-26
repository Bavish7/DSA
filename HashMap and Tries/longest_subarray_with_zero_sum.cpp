#include<iostream>
using namespace std;

// LONGEST SUBARRAY WITH ZERO SUM
// USING UNORDERED MAP - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a map to store cumulative sum and its index.
// 2. Traverse the array, updating cumulative sum.
// 3. If sum equals 0, update answer to current subarray length.
// 4. If sum exists in map, update answer using the difference in indices.
// 5. If sum not in map, store it with its index.
// 6. Return the maximum subarray length.

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            ans = max(ans, i + 1);
        }
        else if (mp.find(sum) != mp.end())
        {
            ans = max(i - mp[sum], ans);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return ans;
}
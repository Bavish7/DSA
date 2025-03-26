#include<iostream>
using namespace std;

// NUMBER OF LONGEST INCREASING SEQUENCES (LEETCODE 673)
// USING LIS AND COUNT ARRAYS - TC=O(N^2), SC=O(N)

// Steps:
// 1. Initialize two arrays: dp[i] to track the length of LIS ending at index i, cnt[i] to track the number of such LIS.
// 2. Traverse the array and for each element nums[i], check all previous elements nums[j] where j < i:
//    a. If nums[i] > nums[j] and dp[i] < dp[j] + 1, update dp[i] to dp[j] + 1 and set cnt[i] to cnt[j].
//    b. If nums[i] > nums[j] and dp[i] == dp[j] + 1, increment cnt[i] by cnt[j] (multiple subsequences found).
// 3. Keep track of the maximum length of LIS found.
// 4. Sum counts in cnt[i] where dp[i] equals the maximum length to get the final result.

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int maxLen = 1;
    vector<int> dp(n, 1), cnt(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                cnt[i] = cnt[j];
            }
            else if (nums[i] > nums[j] && dp[i] == dp[j] + 1)
            {
                cnt[i] += cnt[j];
            }
        }
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxLen)
            count += cnt[i];
    }
    return count;
}
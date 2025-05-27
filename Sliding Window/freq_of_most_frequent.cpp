#include<iostream>
using namespace std;

// FREQUENCY OF THE MOST FREQUENT ELEMENT (LEETCODE 1838)
// USING SORTING AND SLIDING WINDOW - TC=O(N*LOGN), SC=O(1)

// Steps:
// 1. Sort the array to align equal or smaller numbers close to each other for efficient grouping.
// 2. Use a sliding window to calculate the sum of elements within the window (`currentSum`).
// 3. Maintain a valid window where adding `k` to the elements within the window makes all elements equal to `nums[right]`.
// 4. If the condition is violated (`currentSum + k < nums[right] * window size`), shrink the window by moving the left pointer.
// 5. Track the maximum window size observed during the process as the result.

int maxFrequency(vector<int> &nums, int k)
{
    int maxFrequency = 0;
    long currentSum = 0;
    sort(nums.begin(), nums.end());
    for (int left = 0, right = 0; right < nums.size(); ++right)
    {
        currentSum += nums[right];
        while (currentSum + k < static_cast<long>(nums[right]) * (right - left + 1))
        {
            currentSum -= nums[left];
            left++;
        }
        maxFrequency = max(maxFrequency, right - left + 1);
    }
    return maxFrequency;
}
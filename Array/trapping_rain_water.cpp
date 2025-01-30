#include<iostream>
using namespace std;

// TRAPPING RAIN WATER (LEETCODE 42)
// USING PREFIX AND SUFFIX SUM - TC=O(N), SC=O(N)

// Steps:
// 1. Create two arrays, `prefixMax` and `suffixMax`:
//      - `prefixMax[i]` stores the maximum height from the start up to index `i`.
//      - `suffixMax[i]` stores the maximum height from the end up to index `i`.
// 2. Compute `prefixMax` by iterating from left to right, updating each index with the max of the previous max and the current height.
// 3. Compute `suffixMax` by iterating from right to left, updating each index with the max of the next max and the current height.
// 4. Calculate total trapped water by iterating through each index:
//      - For each `height[i]`, add the difference between `min(prefixMax[i], suffixMax[i])` and `height[i]` to `total` if it's positive.
// 5. Return `total` as the final amount of water trapped.

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);
    prefixMax[0] = height[0];
    suffixMax[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (height[i] < prefixMax[i] && height[i] < suffixMax[i])
        {
            total += min(prefixMax[i], suffixMax[i]) - height[i];
        }
    }
    return total;
}

// USING TWO POINTERS - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize pointers `left` (start) and `right` (end) of the height array, as well as `leftMax` and `rightMax` to track maximum heights seen so far.
// 2. Move pointers towards each other based on the smaller height at either end:
//      - If `height[left] < height[right]`, check if `height[left]` is smaller than `leftMax`.
//          - If true, add `leftMax - height[left]` to `total` for trapped water at that index.
//          - If false, update `leftMax` to `height[left]`.
//      - If `height[right] <= height[left]`, check if `height[right]` is smaller than `rightMax`.
//          - If true, add `rightMax - height[right]` to `total` for trapped water at that index.
//          - If false, update `rightMax` to `height[right]`.
// 3. Move the `left` pointer right if it’s less, or the `right` pointer left otherwise, until they meet.
// 4. Return `total`, the final sum of trapped water.

int trap(vector<int> &height)
{
    int leftMax = 0, rightMax = 0, total = 0;
    int left = 0, right = height.size() - 1;
    while (left <= right)
    {
        if (height[left] < height[right])
        {
            if (leftMax > height[left])
            {
                total += leftMax - height[left];
            }
            else
            {
                leftMax = height[left];
            }
            left++;
        }
        else
        {
            if (rightMax > height[right])
            {
                total += rightMax - height[right];
            }
            else
            {
                rightMax = height[right];
            }
            right--;
        }
    }
    return total;
}
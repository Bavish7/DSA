#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

// FIND FIRST AND LAST POSITION OF ELEMENT IN SORTED ARRAY (LEETCODE 34)
// USING BINARY SEARCH - TC=O(LOGN), SC=O(1)

// Steps:
// 1. Implement binary search for finding the starting position of the target element.
// 2. Modify the binary search for finding the ending position of the target element.
// 3. Combine both functions to return the vector with first and last positions of the element.

int startPos(vector<int> &nums, int n, int target)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int endPos(vector<int> &nums, int n, int target)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int n = nums.size();
    ans.push_back(startPos(nums, n, target));
    ans.push_back(endPos(nums, n, target));
    return ans;
}
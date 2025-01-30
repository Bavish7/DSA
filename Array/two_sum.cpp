#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// TWO SUM (LEETCODE 1)
// USING NESTED FOR LOOPS - TC=O(N^2), SC=O(1)
void twoSum(int nums[], int target, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                cout << i << " " << j;
            }
        }
    }
    cout << "";
}

// USING SORTING AND TWO POINTERS - TC=O(N*LOGN), SC=O(N)
// Steps:
// 1. Create a vector of pairs 'p' to store {value, index} of each element in 'nums'.
// 2. Populate 'p' by iterating through 'nums' and storing each element with its index.
// 3. Sort 'p' based on the 'value' of each pair to enable two-pointer traversal.
// 4. Initialize two pointers, 'start' at the beginning and 'end' at the end of 'p'.
// 5. Use two pointers to find two indices where the sum of their corresponding values equals 'target':
//    - Calculate the sum of values pointed by 'start' and 'end'.
//    - If sum equals 'target', store the indices of these elements and return.
//    - If sum is greater than 'target', decrement 'end' to decrease the sum.
//    - If sum is less than 'target', increment 'start' to increase the sum.
// 6. Return an empty vector if no such pair is found that sums up to 'target'.

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> p;
    for (int i = 0; i < nums.size(); i++)
    {
        int index = i;
        int value = nums[i];
        p.push_back({value, index});
    }
    sort(p.begin(), p.end());
    int start = 0;
    int end = nums.size() - 1;
    vector<int> ans;
    while (start < end)
    {
        int sum = p[start].first + p[end].first;
        if (sum == target)
        {
            ans.push_back(p[start].second);
            ans.push_back(p[end].second);
            return ans;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return ans;
}

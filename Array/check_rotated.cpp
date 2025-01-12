#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// CHECK IF ARRAY IS SORTED AND ROTATED (LEETCODE 1752)
// USING FOR LOOP - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize a counter to count the number of inversions.
// 2. Iterate through the array and count the number of times an element is greater than the next element.
// 3. Check if the last element is greater than the first element and increment the counter if true.
// 4. Return true if there is at most one inversion, indicating the array is rotated and sorted.

bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count++;
    }
    return count <= 1;
}
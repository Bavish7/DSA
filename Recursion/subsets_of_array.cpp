#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// SUBSETS OF AN ARRAY (LEETCODE 78)
// USING RECURSION - TC=O(2^N), SC=O(N * 2^N)

// Steps:
// 1. **Recursive Backtracking Function (`solve`)**:
//    - **Base Case**: If we've processed all elements (index >= nums.size()):
//      - Add the current `output` subset to the result set `ans`.
//      - Return to explore other subsets.
//    - **Recursive Case**:
//      - **Exclude the Current Element**:
//        - Recur to process the next element without including the current one.
//      - **Include the Current Element**:
//        - Add the current element to `output`.
//        - Recur to process the next element with the current one included in the subset.
//        - Backtrack by removing the element from `output` to explore other subsets without it.
//
// 2. **Invoke Recursive Function**:
//    - Start the recursive function with an empty `output` subset and an initial index of 0.
//    - Collect all possible subsets in the `ans` vector.

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }
    // exclude
    solve(nums, output, index + 1, ans);
    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

// SUBSETS II (LEETCODE 90)
// USING RECURSION - TC=O(2^N), SC=O(N * 2^N)

// Steps:
// 1. Sort the input array to group duplicates together.
// 2. Use a recursive function `findSubsets` to explore all possible subsets:
//    - Base Case: Push the current subset (`ds`) into the result (`ans`).
//    - Recursive Case: Iterate through the array starting from the current index (`ind`):
//        a. Skip duplicates by checking if the current element equals the previous one (except at the starting index).
//        b. Include the current element in the subset and recursively call for the next index.
//        c. Backtrack by removing the last element to explore other subsets.
// 3. Return the result containing all unique subsets.

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    return ans;
}
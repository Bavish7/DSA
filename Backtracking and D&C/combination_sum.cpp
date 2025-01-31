#include<iostream>
using namespace std;

// COMBINATION SUM (LEETCODE 39)
// USING RECURSION AND BACKTRACKING - TC=O(2^T), SC=O(T)

// Steps:
// 1. If target becomes 0, add the current combination (v) to the answer list (ans) and return.
// 2. If target becomes negative, return as no valid combination is possible.
// 3. Iterate through the candidates starting from the current index to allow repeated elements:
//    a. Add the current candidate to the combination (v).
//    b. Recursively call solve with the reduced target and the same index to allow repetition.
//    c. Backtrack by removing the last added element to explore other combinations.
// 4. The main function initializes the required data structures and starts the recursion.

void solve(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0)
    {
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        v.push_back(candidates[i]);
        solve(candidates, target - candidates[i], v, ans, i);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> v;
    solve(candidates, target, v, ans, 0);
    return ans;
}

// COMBINATION SUM II (LEETCODE 40)
// USING RECURSION AND BACKTRACKING - TC=O(2^N), SC=O(N)

// Steps:
// 1. If target becomes 0, add the current combination (v) to the answer list (ans) and return.
// 2. If target becomes negative, return as no valid combination is possible.
// 3. Iterate through the candidates starting from the current index:
//    a. Skip duplicates by checking if the current candidate is the same as the previous one.
//    b. Add the current candidate to the combination (v).
//    c. Recursively call solve with the reduced target and the next index to avoid repetition of the same element.
//    d. Backtrack by removing the last added element to explore other combinations.
// 4. The main function sorts the candidates, initializes the required data structures, and starts the recursion.

void solve(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0)
    {
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        v.push_back(candidates[i]);
        solve(candidates, target - candidates[i], v, ans, i + 1);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    solve(candidates, target, v, ans, 0);
    return ans;
}

// COMBINATION SUM III (LEETCODE 216)
// USING RECURSION AND BACKTRACKING - TC=O(9!), SC=O(K)

// Steps:
// 1. Use a recursive function `solve` to find all combinations of `k` numbers that sum up to `n`.
//    - Base Case: If `k == 0` and `n == 0`, the current combination (`output`) is valid. Add it to the result (`ans`).
//    - Pruning: If `k < 0` or `n < 0`, terminate the recursion (invalid combination).
// 2. Start from the current number `cnum` and iterate through numbers [1...9]:
//    - Include the current number in the combination (`output`) and reduce `k` and `n`.
//    - Recursively call `solve` for the next number (`cnum + 1`) to maintain unique elements.
//    - Backtrack by removing the last element from the combination after recursion.
// 3. Return the result containing all valid combinations.

void solve(int k, int n, int cnum, vector<vector<int>> &ans, vector<int> &output)
{
    if (k == 0 && n == 0)
    {
        ans.push_back(output);
        return;
    }
    if (k < 0 || n < 0)
    {
        return;
    }
    for (int i = cnum; i <= 9; i++)
    {
        output.push_back(i);
        solve(k - 1, n - i, i + 1, ans, output);
        output.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> output;
    vector<vector<int>> ans;
    solve(k, n, 1, ans, output);
    return ans;
}

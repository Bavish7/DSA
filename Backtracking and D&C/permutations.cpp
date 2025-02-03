#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// PERMUTATIONS (LEETCODE 46)
// USING RECURSION AND BACKTRACKING - TC=O(N*N!), SC=O(N)

// Steps:
// 1. Base Case: When the index reaches the end of the list, add the current permutation to the results.
// 2. Swap each element from the current index to the end to create new permutations.
// 3. Recursively call the function to continue generating permutations for the next index.
// 4. Swap back the elements to restore the original list for the next permutation.

void solve(vector<int> nums, int index, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, index, ans);
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    vector<vector<int>> ans;
    ans = permute(nums);
    for (int i = 0; i < ans.size();i++){
        for (int j = 0; j < n;j++){
            cout << ans[i][j]<<"";
        }
        cout << endl;
    }
}

// USING INBUILT FUNCTION - TC=O(N*N!), SC=O(N*N!)
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> vec;
    sort(nums.begin(), nums.end());
    vec.push_back(nums);
    while (next_permutation(nums.begin(), nums.end()))
    {
        vec.push_back(nums);
    }
    return vec;
}

// PERMUTATIONS II (LEETCODE 47)
// USING RECURSION AND BACKTRACKING - TC=O(N*N!), SC=O(N)

// Steps:
// 1. If index reaches the size of nums, add the current permutation to the answer list (ans) and return.
// 2. Use an unordered_map to keep track of the elements already visited at the current index to avoid duplicates.
// 3. Iterate through nums from index to the end:
//    a. If the current element has already been used at this index (visited is true), skip it.
//    b. Mark the current element as visited.
//    c. Swap the current element with the element at the current index to form a new permutation.
//    d. Recursively call solve with the next index.
//    e. Backtrack by swapping the elements back to their original positions to explore other permutations.
// 4. The main function initializes the required data structures and starts the recursion.

void solve(vector<int> nums, int index, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    unordered_map<int, bool> visited;
    for (int i = index; i < nums.size(); i++)
    {
        if (visited[nums[i]] == true)
        {
            continue;
        }
        visited[nums[i]] = true;
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, index, ans);
    return ans;
}

// USING INBUILT FUNCTION - TC=O(N*N!), SC=O(N*N!)
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> vec;
    sort(nums.begin(), nums.end());
    vec.push_back(nums);
    while (next_permutation(nums.begin(), nums.end()))
    {
        vec.push_back(nums);
    }
    return vec;
}
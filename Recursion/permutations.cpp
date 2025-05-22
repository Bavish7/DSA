#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// PERMUTATIONS OF A NUMBER (LEETCODE 46)
// USING RECURSION AND BACKTRACKING - TC=O(N*N!), SC=O(N)

// Steps:
// 1. Base Case: When the index reaches the end of the list, add the current permutation to the results.
// 2. Swap each element from the current index to the end to create new permutations.
// 3. Recursively call the function to continue generating permutations for the next index.
// 4. Swap back the elements to restore the original list for the next permutation.

void solve(vector<int> nums, int index, vector<vector<int>> &ans)
{
    // base case
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        // backtrack
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
#include<iostream>
using namespace std;

// PRODUCT OF ARRAY EXCEPT SELF (LEETCODE 238)
// USING PREFIX AND SUFFIX ARRAY - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize two arrays `prefix` and `suffix` to store prefix and suffix products respectively:
//    - `prefix[i]`: Product of all elements to the left of `i` (prefix[0] = 1).
//    - `suffix[i]`: Product of all elements to the right of `i` (suffix[n - 1] = 1).
// 2. Compute prefix products from left to right and store them in `prefix`.
// 3. Compute suffix products from right to left and store them in `suffix`.
// 4. Multiply the corresponding elements of `prefix` and `suffix` for each index to get the required result.
// 5. Return the `ans` vector containing the products.

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    prefix[0] = 1;
    suffix[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = nums[i - 1] * prefix[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = nums[i + 1] * suffix[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        ans.push_back(prefix[i] * suffix[i]);
    }
    return ans;
}

// USING CONSTANT SPACE - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize the `ans` vector to store the result.
// 2. Compute the prefix products and store them in the `ans` vector.
// 3. Initialize a variable `suffix` to store the product of all elements to the right of the current element.
// 4. Update the `ans` vector by multiplying the corresponding elements of `ans` and `suffix`.
// 5. Update the `suffix` variable by multiplying it with the current element.
// 6. Return the `ans` vector containing the products.

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    ans.push_back(1);
    for (int i = 1; i < n; i++)
    {
        ans.push_back(nums[i - 1] * ans[i - 1]);
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = ans[i] * suffix;
        suffix = suffix * nums[i];
    }
    return ans;
}
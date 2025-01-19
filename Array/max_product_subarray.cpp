#include<iostream>
using namespace std;

// MAXIMUM PRODUCT SUBARRAY (LEETCODE 152)
// USING NESTED FOR LOOPS - TC=O(N^2), SC=O(1)

// Steps:
// 1. Initialize `maxProduct` to 0 to track the maximum product encountered.
// 2. Handle the edge case where the array has a single element by returning it as the result.
// 3. Use two nested loops:
//    - Outer loop iterates through the starting indices of subarrays.
//    - Inner loop iterates through the ending indices of subarrays.
// 4. For each subarray:
//    - Calculate the product of its elements.
//    - Update `maxProduct` if the current product is greater than `maxProduct`.
// 5. After evaluating all subarrays, return `maxProduct`.

int maxProduct(vector<int> &nums)
{
    int maxProduct = 0;
    int n = nums.size();
    if (n == 1)
        return nums[0];
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= nums[j];
            maxProduct = max(maxProduct, product);
        }
    }
    return maxProduct;
}

// USING PREFIX AND SUFFIX PRODUCTS - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize `maxProduct` to INT_MIN to store the maximum product.
// 2. Use two running products, `prefix` (from start) and `suffix` (from end), initialized to 1.
// 3. Traverse the array:
//    - Reset `prefix` or `suffix` to 1 if they become 0.
//    - Update `prefix` with the current element from the start and `suffix` from the end.
//    - Update `maxProduct` with the maximum of `prefix`, `suffix`, and `maxProduct`.
// 4. Return `maxProduct` after processing all elements.

int maxProduct(vector<int> &nums)
{
    int maxProduct = INT_MIN;
    int prefix = 1, suffix = 1;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[n - i - 1];
        maxProduct = max(maxProduct, max(prefix, suffix));
    }
    return maxProduct;
}
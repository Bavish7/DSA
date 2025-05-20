#include<iostream>
using namespace std;

// 0 1 KNAPSACK PROBLEM 
// USING RECURSION - TC=O(2^N), SC=O(N)

// Steps:
// 1. Base Case: If the current index is equal to the total number of items `n` or if the remaining capacity `w` is 0, return 0.
// 2. Include Case: If the weight of the current item is less than or equal to the remaining capacity `w`, compute the profit by including the current item and recursively solve the problem for the next item with updated capacity `w - weights[index]` and index `index + 1`.
// 3. Exclude Case: Compute the profit by excluding the current item and recursively solve the problem for the next item with the same capacity `w` and index `index + 1`.
// 4. Return the Maximum Profit: The maximum profit is the maximum of the include and exclude cases.

int solveUsingRec(vector<int> &values, vector<int> &weights, int n, int w, int index)
{
    if (index == n || w == 0)
    {
        return 0;
    }
    int include = 0;
    if (weights[index] <= w)
    {
        include = values[index] + solveUsingRec(values, weights, n, w - weights[index], index + 1);
    }
    int exclude = 0 + solveUsingRec(values, weights, n, w, index + 1);
    int ans = max(include, exclude);
    return ans;
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    int index = 0;
    int ans = solveUsingRec(values, weights, n, w, index);
    return ans;
}
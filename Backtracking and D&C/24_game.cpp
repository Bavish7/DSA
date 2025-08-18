#include<iostream>
using namespace std;

// 24 GAME (LEETCODE 679)
// USING REECURSION AND BACKTRACKING - TC=O(1), SC=O(1)

// Steps:
// 1. Base case → if only one number remains, check if it's ≈ 24 (within epsilon).
// 2. Pick every pair (i, j) of numbers from the list.
// 3. Remove them and compute all possible results using {+, -, *, /} (both orders for - and /).
// 4. Append each result to the reduced list and recursively solve.
// 5. If any recursive call returns true, propagate true upwards.
// 6. If no combination leads to 24, return false.

double epsilon = 1e-6;
bool solve(vector<double> &nums)
{
    if (nums.size() == 1)
    {
        return abs(nums[0] - 24.0) <= epsilon;
    }
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vector<double> temp;
            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j)
                {
                    temp.push_back(nums[k]);
                }
            }
            double a = nums[i], b = nums[j];
            vector<double> operations = {a + b, a - b, b - a, a * b};
            if (a != 0.0)
            {
                operations.push_back(b / a);
            }
            if (b != 0.0)
            {
                operations.push_back(a / b);
            }
            for (double &op : operations)
            {
                temp.push_back(op);
                if (solve(temp) == true)
                    return true;
                temp.pop_back();
            }
        }
    }
    return false;
}
bool judgePoint24(vector<int> &cards)
{
    vector<double> nums;
    for (int i = 0; i < cards.size(); i++)
    {
        nums.push_back(1.0 * cards[i]);
    }
    return solve(nums);
}
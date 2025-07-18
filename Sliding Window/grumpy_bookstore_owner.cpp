#include<iostream>
using namespace std;

// GRUMPY BOOKSTORE OWNER (LEETCODE 1052)
// USING FIXED SIZE SLIDING WINDOW - TC=O(N), SC=O(1)

// Steps:
// 1. Calculate initial satisfied customers where grumpy[i] == 0 (owner not grumpy).
// 2. For the first `minutes` window, calculate the extra customers that could be satisfied if the owner suppresses grumpiness.
// 3. Use a sliding window of size `minutes` to find the maximum number of such extra satisfiable customers.
// 4. Add this max additional satisfiable count to the always satisfied base to get the final answer.

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int n = customers.size();
    int left = 0, right = minutes, satisfied = 0;
    int unsatisfied = 0, maxUnsatisfied = 0;
    for (int i = 0; i < n; i++)
    {
        if (grumpy[i] == 0)
            satisfied += customers[i];
    }
    for (int i = 0; i < minutes; i++)
    {
        if (grumpy[i] == 1)
            unsatisfied += customers[i];
    }
    maxUnsatisfied = unsatisfied;
    while (right < n)
    {
        if (grumpy[right] == 1)
            unsatisfied += customers[right];
        if (grumpy[left] == 1)
            unsatisfied -= customers[left];
        maxUnsatisfied = max(maxUnsatisfied, unsatisfied);
        left++, right++;
    }
    return maxUnsatisfied + satisfied;
}
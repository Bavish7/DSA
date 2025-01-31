#include<iostream>
using namespace std;

// BEAUTIFUL ARRANGEMENT (LEETCODE 526)
// USING RECURSION AND BACKTRACKING - TC=O(K), SC=O(N)

// Steps:
// 1. If num exceeds n, increment ans as a valid arrangement is found and return.
// 2. Loop through all positions from 1 to n and check if the current position is unused (v[i] == 0) and satisfies the condition (num % i == 0 or i % num == 0).
// 3. If valid, assign the current num to the position, recurse with num + 1, and then reset the position to 0 (backtrack).
// 4. Continue this until all valid arrangements are counted and return ans.

void solve(vector<int> &v, int &ans, int n, int num)
{
    if (num == n + 1)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0 && (num % i == 0 || i % num == 0))
        {
            v[i] = num;
            solve(v, ans, n, num + 1);
            v[i] = 0;
        }
    }
}
int countArrangement(int n)
{
    int ans = 0;
    vector<int> v(n + 1);
    solve(v, ans, n, 1);
    return ans;
}
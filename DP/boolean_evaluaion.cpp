#include<iostream>
using namespace std;

// BOOLEAN EVALUATION
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^3), SC=O(N^2)

// Steps:
// 1. Define a recursive function `solveUsingMem(i, j, isTrue, exp)` that evaluates the expression between indices `i` and `j`.
// 2. Base case:
//    - If `i > j`, return 0 (invalid case).
//    - If `i == j`, return 1 if the single character matches `isTrue` condition (`'T'` or `'F'`).
// 3. Iterate over possible operators (`&`, `|`, `^`) between indices `i` and `j`.
// 4. For each operator, compute left and right subexpression results for both true and false cases.
// 5. Combine the results according to the operator logic (`&`, `|`, `^`) based on the target `isTrue` value.
// 6. Apply modulo operation (`% mod`) to handle large numbers.
// 7. Return the result stored in `dp[i][j][isTrue]`.

#define ll long long
int mod = 1000000007;
ll solveUsingMem(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        ll lt = solveUsingMem(i, ind - 1, 1, exp, dp);
        ll rt = solveUsingMem(ind + 1, j, 1, exp, dp);
        ll lf = solveUsingMem(i, ind - 1, 0, exp, dp);
        ll rf = solveUsingMem(ind + 1, j, 0, exp, dp);
        if (exp[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (lt * rt) % mod) % mod;
            else
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
            else
                ways = (ways + (lf * rf) % mod) % mod;
        }
        else
        {
            if (isTrue)
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
            else
                ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string &exp)
{
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solveUsingMem(0, n - 1, 1, exp, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^3), SC=O(N^2)
// Steps:
// 1. Initialize a 3D DP table `dp[i][j][isTrue]` to store results for subproblems between indices `i` and `j`.
// 2. Base initialization:
//    - If `i == j`, set `dp[i][i][1] = 1` if `exp[i] == 'T'` and `dp[i][i][0] = 1` if `exp[i] == 'F'`.
// 3. Iterate over all subproblem lengths and compute the result for all partitions using possible operators.
// 4. For each partition point `ind` with an operator, compute left (`lt`, `lf`) and right (`rt`, `rf`) results for both true and false cases.
// 5. Use appropriate logic based on operators (`&`, `|`, `^`) and `isTrue` conditions to update `dp[i][j][isTrue]`.
// 6. Apply modulo operation (`% mod`) to avoid overflow.
// 7. Return `dp[0][n-1][1]`, the final result for the whole expression when evaluated as true.

ll solveUsingTab(string &exp)
{
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for (int i = 0; i < n; i++)
    {
        dp[i][i][1] = exp[i] == 'T';
        dp[i][i][0] = exp[i] == 'F';
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int isTrue = 0; isTrue <= 1; isTrue++)
            {
                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2)
                {
                    ll lt = dp[i][ind - 1][1];
                    ll rt = dp[ind + 1][j][1];
                    ll lf = dp[i][ind - 1][0];
                    ll rf = dp[ind + 1][j][0];
                    if (exp[ind] == '&')
                    {
                        if (isTrue)
                            ways = (ways + (lt * rt) % mod) % mod;
                        else
                            ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
                    }
                    else if (exp[ind] == '|')
                    {
                        if (isTrue)
                            ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
                        else
                            ways = (ways + (lf * rf) % mod) % mod;
                    }
                    else
                    {
                        if (isTrue)
                            ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
                        else
                            ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}
int evaluateExp(string &exp)
{
    return solveUsingTab(exp);
}
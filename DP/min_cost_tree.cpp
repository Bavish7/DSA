#include<iostream>
using namespace std;

// MININMUM COST TREE FROM LEAF VALUES (LEETCODE 1130)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^3), SC=O(N^2)

// Steps:
// 1. Base Cases:
//    a. If start >= end, return 0.
//    b. If dp[start][end] is not -1, return dp[start][end].
// 2. Initialize ans to INT_MAX.
// 3. Iterate through each possible root i from start to end - 1:
//    a. Calculate the sum using the formula:
//         sum = maxi[{start, i}] * maxi[{i + 1, end}] + solveUsingMem(arr, maxi, start, i, dp) + solveUsingMem(arr, maxi, i + 1, end, dp).
//    b. Update ans with the minimum value of ans and sum.
// 4. Store ans in dp[start][end].
// 5. Return dp[start][end], which contains the minimum cost of constructing the tree from arr[start] to arr[end].

int solveUsingMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int ans = INT_MAX;
    for (int i = start; i < end; i++)
    {
        int sum = maxi[{start, i}] * maxi[{i + 1, end}] + solveUsingMem(arr, maxi, start, i, dp) + solveUsingMem(arr, maxi, i + 1, end, dp);
        ans = min(ans, sum);
        dp[start][end] = ans;
    }
    return dp[start][end];
}
int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int start = 0;
    int end = n - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(arr, maxi, start, end, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^3), SC=O(N^2)
// Steps:
// 1. Initialize a 2D vector dp with dimensions (n+1) x (n+1) where n is the size of arr.
//    - dp[start][end] will store the minimum cost of constructing the tree from arr[start] to arr[end].
// 2. Iterate through the array from end to start (start = n-1 to 0):
//    a. Iterate through the array from start + 1 to n (end = start + 1 to n):
//       - Initialize ans to INT_MAX for each pair (start, end).
//       b. Iterate through each possible root i from start to end:
//          Calculate the sum using the formula:
//            sum = maxi[{start, i}] * maxi[{i + 1, end}] + dp[start][i] + dp[i + 1][end].
//          Update ans with the minimum value of ans and sum.
//       c. Store ans in dp[start][end].
// 3. Return dp[0][n-1], which contains the minimum cost of constructing the tree from arr[0] to arr[n-1].

int solveUsingTab(vector<int> &arr, map<pair<int, int>, int> &maxi, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int start = n - 1; start >= 0; start--)
    {
        for (int end = start + 1; end < n; end++)
        {
            int ans = INT_MAX;
            for (int i = start; i <= end; i++)
            {
                int sum = maxi[{start, i}] * maxi[{i + 1, end}] + dp[start][i] + dp[i + 1][end];
                ans = min(ans, sum);
                dp[start][end] = ans;
            }
        }
    }
    return dp[0][n - 1];
}
int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int ans = solveUsingTab(arr, maxi, n);
    return ans;
}

// USING STACK - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize ans to 0.
// 2. Initialize stack st with INT_MAX at the bottom.
// 3. Iterate through each element x in array A:
//    a. While the top of stack st is less than or equal to x:
//         i. Pop the top element temp from stack st.
//         ii. Add temp * min(st.top(), x) to ans.
//    b. Push x onto stack st.
// 4. While stack st has more than 2 elements:
//    a. Pop the top element temp from stack st.
//    b. Add temp * st.top() to ans.
// 5. Return ans, which contains the minimum cost of constructing the tree from leaf values in array A.

int mctFromLeafValues(vector<int> &A)
{
    int ans = 0;
    stack<int> st;
    st.push(INT_MAX);
    for (auto x : A)
    {
        while (st.top() <= x)
        {
            int temp = st.top();
            st.pop();
            ans += temp * min(st.top(), x);
        }
        st.push(x);
    }
    while (st.size() > 2)
    {
        int temp = st.top();
        st.pop();
        ans += (temp * st.top());
    }
    return ans;
}
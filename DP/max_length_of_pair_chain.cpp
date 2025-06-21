#include<iostream>
using namespace std;

// MAXIMUM LENGTH OF PAIR CHAIN (LEETCODE 646)
// TOP-DOWN MEMOIZATION - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Sort the input pairs by their first element to simplify compatibility checks.
// 2. Use recursion with memoization to explore all subsequence options.
// 3. At each step, choose to either:
//    - Include the current pair if it doesn't overlap with the previous included pair.
//    - Exclude the current pair and move to the next.
// 4. Store the result in a DP table `dp[prev+1][curr]` to avoid recomputation.
// 5. Start with curr = 0 and prev = -1 to represent no previous pair initially.

int solveUsingMem(int curr, int prev, vector<vector<int>>&pairs, vector<vector<int>>&dp){
    if(curr==pairs.size()) return 0;
    if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];
    int include=0;
    if(prev==-1 || pairs[prev][1]<pairs[curr][0]){
        include=1+solveUsingMem(curr+1,curr,pairs,dp);
    }
    int exclude=solveUsingMem(curr+1,prev,pairs,dp);
    return dp[prev+1][curr]=max(include,exclude);
}
int findLongestChain(vector<vector<int>>& pairs) {
    int n=pairs.size();
    sort(pairs.begin(),pairs.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solveUsingMem(0,-1,pairs,dp);
}

// BOTTOM-UP TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Sort the input pairs to ensure the order for valid chaining.
// 2. Use a 2D DP table dp[prev+1][curr+1] where:
//    - `prev` is the index of the last chosen pair (or -1 initially).
//    - `curr` is the index of the current pair being considered.
// 3. Fill the table in bottom-up fashion starting from the last index.
// 4. For each (prev, curr), either:
//    - Include `curr` if it doesn't overlap with `prev`, and move to curr+1.
//    - Exclude `curr` and continue.
// 5. Store the best result in dp[prev+1][curr+1].
// 6. Final answer is stored in dp[0][1] corresponding to prev=-1 and curr=0.

int solveUsingTab(vector<vector<int>>&pairs){
    int n=pairs.size();
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    for(int prev=n-1;prev>=-1;prev--){
        for(int curr=n-1;curr>=0;curr--){
            int include=0;
            if(prev==-1 || pairs[prev][1]<pairs[curr][0]){
                include=1+dp[curr+1][curr+2];
            }
            int exclude=dp[prev+1][curr+2];
            dp[prev+1][curr+1]=max(include,exclude);
        }
    }
    return dp[0][1];
}
int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(),pairs.end());
    return solveUsingTab(pairs);
}

// USING GREEDY ALGORITHM - TC=O(N*LOGN), SC=O(1)
// Steps:
// 1. Sort the pairs by their second element to prioritize early finishing intervals.
// 2. Initialize `curr` to track the end of the last selected pair.
// 3. Iterate over sorted pairs:
//    - If current pair's start > `curr`, it can be added to the chain.
//    - Update `curr` to the current pair's end and increment count.
// 4. Return the total count of non-overlapping pairs selected (maximum chain length).

bool static comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), comp);
    int curr = INT_MIN, ans = 0;
    for (auto &pair : pairs)
    {
        if (curr < pair[0])
        {
            curr = pair[1];
            ans++;
        }
    }
    return ans;
}

#include<iostream>
using namespace std;

// COMBINATIONS (LEETCODE 77)
// USING BACKTRACKING - TC=O(N!/(K!(N-K)!)), SC=O(K)

// Steps:
// 1. Start with an empty combination (`temp`) and index 1.
// 2. At each step, choose the next integer i from index to n:
//    - Add i to `temp`.
//    - Recur with i+1 (since elements must be in increasing order and unique).
//    - Backtrack: remove i from `temp` to explore next choices.
// 3. If `temp` size becomes k, we’ve found a valid combination → add to result.

void backtrack(int index, vector<int>&temp,vector<vector<int>>&ans, int n, int k){
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<=n;i++){
        temp.push_back(i);
        backtrack(i+1,temp,ans,n,k);
        temp.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>ans;
    vector<int>temp;
    backtrack(1,temp,ans,n,k);
    return ans;
}
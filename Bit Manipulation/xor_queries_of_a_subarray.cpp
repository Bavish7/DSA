#include<iostream>
using namespace std;

// XOR QUERIES OF A SUBARRAY (LEETCODE 1310)
// USING PREFIX XOR - TC=O(N + Q), SC=O(N)

// Steps:
// 1. Build prefixXor array where prefixXor[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
// 2. For each query [L, R]:
//    - If L == 0 → result = prefixXor[R].
//    - Otherwise → result = prefixXor[R] ^ prefixXor[L-1].
// 3. Store result for each query in ans.
// 4. Return ans.

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    vector<int> prefixXor(n, 0);
    vector<int> ans;
    prefixXor[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixXor[i] = prefixXor[i - 1] ^ arr[i];
    }
    for (auto &query : queries)
    {
        int start = query[0];
        int end = query[1];
        int leftXor = start == 0 ? 0 : prefixXor[start - 1];
        int rightXor = prefixXor[end];
        ans.push_back(leftXor ^ rightXor);
    }
    return ans;
}
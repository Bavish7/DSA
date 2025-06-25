#include<iostream>
using namespace std;

// KTH ANCESTOR OF A TREE NODE (LEETCODE 1483)
// USING BINARY LIFTING - TC=O(N*LOGN+LOGK), SC=O(N*LOGN)

// Steps:
// 1. Preprocessing in constructor:
//    - LOG = max power of 2 needed (ceil(log2(n)) + 1).
//    - `mp[i][j]` will store the 2^i-th ancestor of node `j`.
//    - Initialize `mp[0][i] = parent[i]` (1-step ancestor).
//    - Use dynamic programming to fill `mp[i][j] = mp[i-1][mp[i-1][j]]`, i.e., 2^i-th ancestor by combining two 2^(i-1)-th jumps.
// 2. Querying `getKthAncestor`:
//    - Traverse bits of `k`. For each bit `i` set in `k`, jump to the 2^i-th ancestor using `mp[i][node]`.
//    - Repeat until `k == 0` or `node == -1` (no ancestor exists).
// 3. Returns the k-th ancestor of the node or -1 if it doesn't exist.

class TreeAncestor
{
    int LOG;
    vector<vector<int>> mp;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        LOG = ceil(log2(n)) + 1;
        mp.resize(LOG, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            mp[0][i] = parent[i];
        }

        for (int i = 1; i < LOG; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mp[i - 1][j] != -1)
                    mp[i][j] = mp[i - 1][mp[i - 1][j]];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < LOG && node != -1; i++)
        {
            if (k & (1 << i))
            {
                node = mp[i][node];
            }
        }
        return node;
    }
};

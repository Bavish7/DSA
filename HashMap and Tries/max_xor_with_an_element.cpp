#include<iostream>
using namespace std;

// MAX XOR WITH AN ELEMENT IN AN ARRAY (LEETCODE 1707)
// USING TRIE AND BIT MANIPULATION - TC=O(N*LOGN+Q*LOGQ), SC=O(N+Q)

// Steps:
// 1. Sort `nums` to process queries in increasing order of `ai`.  
// 2. Store queries as `{ai, {xi, index}}` and sort them based on `ai`.  
// 3. Initialize a Trie and an index `ind` to insert numbers from `nums` up to `ai` for each query.  
// 4. For each query, insert all `nums` values `<= ai` into the Trie.  
// 5. Use the Trie to find the maximum XOR value for `xi`.  
// 6. If no numbers are inserted (`ind == 0`), return `-1` for that query.  
// 7. Store results in the correct order using the query index and return the final answer.

class TrieNode
{
public:
    TrieNode *child[2];
    TrieNode()
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};
class Trie
{
public:
    TrieNode *root = new TrieNode();
    void insert(int &number)
    {
        TrieNode *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (number >> i) & 1;
            if (curr->child[bit] == NULL)
            {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
        }
    }
    int findMax(int &number)
    {
        TrieNode *curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (number >> i) & 1;
            int reverse = 1 - bit;
            if (curr->child[reverse] != NULL)
            {
                ans = ans | (1 << i);
                curr = curr->child[reverse];
            }
            else
            {
                curr = curr->child[bit];
            }
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> offQueries;
        int q = queries.size();
        for (int i = 0; i < q; i++)
        {
            offQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(offQueries.begin(), offQueries.end());
        vector<int> ans(q, 0);
        int n = nums.size();
        int ind = 0;
        Trie *t = new Trie();
        for (int i = 0; i < q; i++)
        {
            int ai = offQueries[i].first;
            int xi = offQueries[i].second.first;
            int qInd = offQueries[i].second.second;
            while (ind < n && nums[ind] <= ai)
            {
                t->insert(nums[ind]);
                ind++;
            }
            if (ind == 0)
                ans[qInd] = -1;
            else
                ans[qInd] = t->findMax(xi);
        }
        return ans;
    }
};
#include<iostream>
using namespace std;

// MAX XOR OF TWO NUMBERS IN AN ARRAY (LEETCODE 421)
// USING TRIE AND BIT MANIPULATION - TC=O(N), SC=O(N)

// Steps:
// 1. Trie Node Definition: Define a TrieNode class with two children representing binary digits `0` and `1`.
// 2. Insertion:  
//    - For each number, traverse 32 bits from the most significant to the least significant.  
//    - Insert each bit into the Trie, creating new nodes as necessary.  
// 3. Finding Maximum XOR:  
//    - For each number in `nums`, attempt to select the reverse bit (`1 - bit`) at every position to maximize the XOR value.  
//    - If the reverse bit is unavailable, continue with the same bit.
// 4. Compute Maximum:  
//    - Insert each number in the Trie and compute its XOR with an existing number using `findMax`.  
//    - Track the maximum XOR across all computations.

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
    int findMaximumXOR(vector<int> &nums)
    {
        Trie *t = new Trie();
        for (int i = 0; i < nums.size(); i++)
        {
            t->insert(nums[i]);
        }
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, t->findMax(nums[i]));
        }
        return maxi;
    }
};
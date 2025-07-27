#include<iostream>
using namespace std;

// PSUDO-PALINDROMIC PATHS IN A BINARY TREE (LEETCODE 1457)
// USING PREORDER TRAVERSAL - TC=O(N), SC=O(H)

// Steps:
// 1. Traverse the tree using DFS while tracking digit frequencies using a size-10 array.
// 2. At each leaf node, count how many digits have odd frequencies.
//    - A path can form a palindrome if at most one digit has an odd frequency.
// 3. If the condition is met (oddFreq ≤ 1), increment the global `count`.
// 4. Backtrack after visiting children by decrementing the frequency.
// 5. Return the final count of valid pseudo-palindromic paths from root to leaf.

int count = 0;
void solve(TreeNode *root, vector<int> &freq)
{
    if (!root)
        return;
    freq[root->val]++;
    if (root->left == NULL && root->right == NULL)
    {
        int oddFreq = 0;
        for (int i = 0; i < 10; i++)
        {
            if (freq[i] % 2 != 0)
                oddFreq++;
        }
        if (oddFreq <= 1)
            count++;
    }
    solve(root->left, freq);
    solve(root->right, freq);
    freq[root->val]--;
}
int pseudoPalindromicPaths(TreeNode *root)
{
    vector<int> freq(10, 0);
    solve(root, freq);
    return count;
}

// USING PREORDER TRAVERSAL AND BITMASKING - TC=O(N), SC=O(H)
// Steps:
// 1. Traverse the tree using DFS, passing a bitmask `count` to track parity of digit frequencies.
//    - Use XOR to toggle bits: count ^= (1 << val)
// 2. At each leaf node, check if the path can form a palindrome.
//    - A number can form a palindrome if at most one bit is set in the mask.
//    - This is true when: (count & (count - 1)) == 0
// 3. If valid, increment global `ans`.
// 4. Recursively call left and right child with updated bitmask.
// 5. Return `ans` — the number of pseudo-palindromic root-to-leaf paths.

int ans = 0;
void solve(TreeNode *root, int count)
{
    if (!root)
        return;
    count = (count ^ (1 << root->val));
    if (root->left == NULL && root->right == NULL)
    {
        if ((count & (count - 1)) == 0)
            ans++;
    }
    solve(root->left, count);
    solve(root->right, count);
}
int pseudoPalindromicPaths(TreeNode *root)
{
    solve(root, 0);
    return ans;
}
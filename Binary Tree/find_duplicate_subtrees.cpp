#include<iostream>
using namespace std;

// FIND DUPLICATE SUBTREES (LEETCODE 652)
// USING POST ORDER TRAVERSAL AND SERIALIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Perform post-order traversal to process left and right subtrees before current node.
// 2. Serialize each subtree into a string:
//    - Format: "root_val,left_subtree,right_subtree"
//    - Use "NULL" for null nodes to preserve structure.
// 3. Store each serialized subtree in a hash map with its frequency.
// 4. If a serialization appears exactly once before, add the current root to `ans`.
//    - This ensures we collect only one representative TreeNode per duplicate subtree.
// 5. Return the list of duplicate subtree roots.

string solve(TreeNode *root, unordered_map<string, int> &mp, vector<TreeNode *> &ans)
{
    if (!root)
        return "NULL";
    string s = to_string(root->val) + "," + solve(root->left, mp, ans) + "," + solve(root->right, mp, ans);
    if (mp[s] == 1)
        ans.push_back(root);
    mp[s]++;
    return s;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    vector<TreeNode *> ans;
    unordered_map<string, int> mp;
    solve(root, mp, ans);
    return ans;
}
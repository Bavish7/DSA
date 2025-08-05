#include<iostream>
using namespace std;

// HEIGHT OF BINARY TREE AFTER SUBTREE REMOVAL QUERIES (LEETCODE 2458)
// USING DFS TRAVERSAL AND PREPROCESSING - TC=O(N+Q), SC=O(N)

// Steps:
// 1. Precompute for each node:
//    a. `level[node]` = depth from root
//    b. `height[node]` = height of subtree rooted at node
//    c. For each level, store top 2 maximum subtree heights in `levelMaxHt[level]`
// 2. For each query node:
//    a. Get its level and subtree height.
//    b. Check if its height is the highest at its level.
//       - If yes → use second max height from that level
//       - If not → use the max height
//    c. New height = currLevel + selected height - 1
// 3. Push result into the answer vector.

int findHeight(TreeNode *root, int lev, vector<int> &level, vector<int> &height, vector<pair<int, int>> &levelMaxHt)
{
    if (!root)
        return 0;
    level[root->val] = lev;
    height[root->val] = max(findHeight(root->left, lev + 1, level, height, levelMaxHt), findHeight(root->right, lev + 1, level, height, levelMaxHt)) + 1;
    if (levelMaxHt[lev].first < height[root->val])
    {
        levelMaxHt[lev].second = levelMaxHt[lev].first;
        levelMaxHt[lev].first = height[root->val];
    }
    else if (levelMaxHt[lev].second < height[root->val])
    {
        levelMaxHt[lev].second = height[root->val];
    }
    return height[root->val];
}
vector<int> treeQueries(TreeNode *root, vector<int> &queries)
{
    vector<int> level(100001);
    vector<int> height(100001);
    vector<pair<int, int>> levelMaxHt(100001);
    findHeight(root, 0, level, height, levelMaxHt);
    vector<int> ans;
    for (int &query : queries)
    {
        int currLevel = level[query];
        int currHeight = 0;
        if (levelMaxHt[currLevel].first == height[query])
        {
            currHeight = levelMaxHt[currLevel].second;
        }
        else
            currHeight = levelMaxHt[currLevel].first;
        int res = currLevel + currHeight - 1;
        ans.push_back(res);
    }
    return ans;
}
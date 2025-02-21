#include<iostream>
using namespace std;

// PATH SUM (LEETCODE 112)
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. If root is NULL, return false.
// 2. Add root's value to pathSum.
// 3. If root is a leaf node (both left and right are NULL):
//    - Check if pathSum equals targetSum.
// 4. Recursively check left and right subtrees:
//    - Pass updated pathSum to both recursive calls.
// 5. Return true if either subtree returns true.

bool solve(TreeNode *root, int targetSum, int pathSum)
{
    if (root == NULL)
    {
        return false;
    }
    pathSum += root->val;
    if (root->left == NULL && root->right == NULL)
    {
        if (pathSum == targetSum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool leftSub = solve(root->left, targetSum, pathSum);
    bool rightSub = solve(root->right, targetSum, pathSum);
    return leftSub || rightSub;
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    int pathSum = 0;
    bool ans = solve(root, targetSum, pathSum);
    return ans;
}

// PATH SUM II (LEETCODE 113)
// USING RECURSION - TC=O(N*K), SC=O(N)

// Steps:
// 1. If root is NULL, return.
// 2. Add root's value to sum and push it to temp.
// 3. If root is a leaf node (both left and right are NULL):
//    - If sum equals targetSum, push temp to ans.
//    - Return from the function.
// 4. Recursively traverse left and right subtrees:
//    - Pass updated sum and temp vector to both recursive calls.
void solve(TreeNode *root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &ans)
{
    if (root == NULL)
    {
        return;
    }
    sum += root->val;
    temp.push_back(root->val);
    if (root->left == NULL && root->right == NULL)
    {
        if (targetSum == sum)
        {
            ans.push_back(temp);
        }
        else
        {
            return;
        }
    }
    solve(root->left, targetSum, sum, temp, ans);
    solve(root->right, targetSum, sum, temp, ans);
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    solve(root, targetSum, sum, temp, ans);
    return ans;
}

// PATH SUM III (LEETCODE 437)
// USING RECURSION AND PREORDER TRAVERSAL - TC=O(N^2), SC=O(N)

// Steps:
// 1. Define a helper function `pathFromOneRoot` to count paths starting from the current node with a given sum.
// 2. If the current node is NULL, return as there's no path.
// 3. If the sum equals the node's value, increment the answer counter.
// 4. Recursively call `pathFromOneRoot` for the left and right children, reducing the sum by the node's value.
// 5. In the main function `pathSum`, recursively call `pathFromOneRoot` from every node in the tree to account for paths starting at different nodes.
// 6. Recursively traverse the tree using `pathSum` on the left and right subtrees.
// 7. Return the total count of valid paths after checking all nodes.

int ans = 0;
void pathFromOneRoot(TreeNode *root, long long sum)
{
    if (!root)
        return;
    if (sum == root->val)
    {
        ans++;
    }
    pathFromOneRoot(root->left, sum - root->val);
    pathFromOneRoot(root->right, sum - root->val);
}
int pathSum(TreeNode *root, long long targetSum)
{
    if (root)
    {
        pathFromOneRoot(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }
    return ans;
}

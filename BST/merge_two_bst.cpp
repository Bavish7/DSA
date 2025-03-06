#include<iostream>
using namespace std;

// ALL ELEMENTS IN TWO BSTs (LEETCODE 1305)
// USING INORDER TRAVERSAL AND MERGING 2 SORTED ARRAYS - TC=O(M+N), SC=O(M+N)

// Steps:
// inorderTraversal(root, ans):
// 1. If root is NULL, return.
// 2. Perform inorder traversal on left subtree.
// 3. Push root's value into ans.
// 4. Perform inorder traversal on right subtree.
//
// merge(ans1, ans2):
// 1. Initialize pointers i, j, and k to 0 for ans1, ans2, and ans3 respectively.
// 2. Iterate through ans1 and ans2:
//    a. Compare elements at pointers i and j.
//    b. Append smaller element to ans3 and move respective pointer.
// 3. Append remaining elements of ans1 and ans2 to ans3.
// 4. Return merged sorted array ans3.

void inorderTraversal(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, ans);
    ans.push_back(root->val);
    inorderTraversal(root->right, ans);
}
vector<int> merge(vector<int> &ans1, vector<int> &ans2)
{
    int m = ans1.size();
    int n = ans2.size();
    vector<int> ans3(m + n);
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (ans1[i] < ans2[j])
        {
            ans3[k++] = ans1[i++];
        }
        else
        {
            ans3[k++] = ans2[j++];
        }
    }
    while (i < m)
    {
        ans3[k++] = ans1[i++];
    }
    while (j < n)
    {
        ans3[k++] = ans2[j++];
    }
    return ans3;
}
vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> ans1, ans2;
    inorderTraversal(root1, ans1);
    inorderTraversal(root2, ans2);
    vector<int> ans3 = merge(ans1, ans2);
    return ans3;
}
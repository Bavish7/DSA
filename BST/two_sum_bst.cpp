#include<iostream>
using namespace std;

// TWO SUM 4 - INPUT IS A BST (LEETCODE 653)
// USING INORDER TRAVERSAL AND TWO POINTERS APPROACH - TC=O(N), SC=O(N)

// Steps:
// 1. Perform an in-order traversal of the BST and store the result in a sorted array.
// 2. Use a two-pointer approach to find if there are two elements in the array that sum up to `k`:
//    - Start with pointers at the beginning (`i`) and end (`j`) of the array.
//    - If the sum of the elements at `i` and `j` equals `k`, return `true`.
//    - If the sum is greater than `k`, decrement `j` to reduce the sum.
//    - If the sum is less than `k`, increment `i` to increase the sum.
// 3. If no such pair is found, return `false`.

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
bool findTarget(TreeNode *root, int k)
{
    vector<int> ans;
    inorderTraversal(root, ans);
    int i = 0, j = ans.size() - 1;
    while (i < j)
    {
        if (ans[i] + ans[j] == k)
        {
            return true;
        }
        else if (ans[i] + ans[j] > k)
        {
            j--;
        }
        else if (ans[i] + ans[j] < k)
        {
            i++;
        }
    }
    return false;
}
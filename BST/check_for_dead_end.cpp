#include<iostream>
using namespace std;

// CHECK FOR DEAD END IN A BST 
// USING PREORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps : 
// 1. Use a recursive function to traverse the tree.
// 2. At each node, mark it as visited in an unordered map.
// 3. When a leaf node is encountered, check if its value + 1 and value - 1 are also visited : -If both are visited, it indicates a dead end, so set the answer to true.
// 4. Continue traversing the left and right subtrees recursively.
// 5. Return the result indicating whether a dead end exists.

void solve(TreeNode<int> *root, unordered_map<int, bool> &visited, bool &ans)
{
    if (root == NULL)
        return;
    visited[root->data] = true;
    if (root->left == NULL && root->right == NULL)
    {
        int add1 = root->data + 1;
        int minus1 = root->data - 1 == 0 ? root->data : root->data - 1;
        if (visited.find(add1) != visited.end() && visited.find(minus1) != visited.end())
        {
            ans = true;
            return;
        }
    }
    solve(root->left, visited, ans);
    solve(root->right, visited, ans);
}
bool isDeadEnd(TreeNode<int> *root)
{
    unordered_map<int, bool> visited;
    bool ans = false;
    solve(root, visited, ans);
    return ans;
}
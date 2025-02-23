#include <iostream>
#include <vector>
using namespace std;

// TOP VIEW OF A BINARY TREE
// USING PREORDER TRAVERSAL - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. If root is NULL, return empty ans vector.
// 2. Initialize map m to store horizontal distance and corresponding node value.
// 3. Initialize queue q and push {root, 0} (node and its horizontal distance).
// 4. While q is not empty:
// a. Pop front element from q, get node and horizontal distance (hd).
// b. If hd is not in map m, add hd and node's data to map.
// c. If node has a left child, push {left child, hd - 1} to q.
// d. If node has a right child, push {right child, hd + 1} to q.
// 5. Iterate over map m and push values to ans vector.
// 6. Return ans vector.

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> m;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<TreeNode<int> *, int> temp = q.front();
        q.pop();
        TreeNode<int> *curr = temp.first;
        int hd = temp.second;
        if (m.find(hd) == m.end())
        {
            m[hd] = curr->data;
        }
        if (curr->left)
        {
            q.push({curr->left, hd - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, hd + 1});
        }
    }
    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}
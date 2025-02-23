#include <iostream>
#include <vector>
using namespace std;

// VERTICAL ORDER TRAVERSAL
// USING LEVEL ORDER TRAVERSAL - TC=O(N*LOGN), SC=O(N)

// Steps:
// verticalOrderTraversal(root):
// 1. If root is NULL, return empty ans vector.
// 2. Initialize map m to store horizontal distance and corresponding node values.
// 3. Initialize queue q and push {root, 0} (node and its horizontal distance).
// 4. While q is not empty:
// a. Pop front element from q, get node and horizontal distance (hd).
// b. Append node's data to vector at hd in map m.
// c. If node has a left child, push {left child, hd - 1} to q.
// d. If node has a right child, push {right child, hd + 1} to q.
// 5. Iterate over map m and append values to ans vector.
// 6. Return ans vector.

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, vector<int>> m;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<TreeNode<int> *, int> temp = q.front();
        q.pop();
        TreeNode<int> *curr = temp.first;
        int hd = temp.second;
        m[hd].push_back(curr->data);
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
        for (auto res : i.second)
        {
            ans.push_back(res);
        }
    }
    return ans;
}

// VERTICAL ORDER TRAVERSAL OF A BINARY TREE (LEETCODE 987)
// USING LEVEL ORDER TRAVERSAL - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Use a BFS approach with a queue to perform a level-order traversal.
// 2. Track each node's vertical line index in a `map` and group nodes by their vertical line indices.
// 3. At each level, store nodes in a temporary map (`m1`) to ensure vertical order grouping, sorted by values.
// 4. After processing each level, merge sorted nodes into the main map (`m`) for final grouping.
// 5. Convert the map's values to a 2D vector to return the result.

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    queue<pair<TreeNode *, int>> q;
    map<int, vector<int>> m;
    q.push({root, 0});
    while (q.size() > 0)
    {
        map<int, vector<int>> m1;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            TreeNode *node = it.first;
            int line = it.second;
            m1[line].push_back(node->val);
            q.pop();
            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }
        for (auto it : m1)
        {
            sort(it.second.begin(), it.second.end());
            for (auto x : it.second)
            {
                m[it.first].push_back(x);
            }
        }
    }
    vector<vector<int>> ans;
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}
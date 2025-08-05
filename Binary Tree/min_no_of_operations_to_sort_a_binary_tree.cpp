#include<iostream>
using namespace std;

// MINIMUM NUMBER OF OPERATIONS TO SORT A BINARY TREE LEVEL BY LEVEL (LEETCODE 2471)
// USING BFS TRAVERSAL AND UNORDERED MAP- TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Traverse the tree level by level using BFS.
// 2. For each level, store the values of nodes in a vector.
// 3. Count the minimum number of swaps to sort the vector using:
//    - Store original indices of elements.
//    - Detect cycles formed by incorrect positions.
//    - Each cycle of length `k` needs `k - 1` swaps.
// 4. Add the swap count from all levels to get the total operations.
// 5. Return the total minimum operations needed.

int minSwaps(vector<int> &v)
{
    int swaps = 0;
    vector<int> arr = v;
    sort(arr.begin(), arr.end());
    unordered_map<int, int> pos;
    for (int i = 0; i < v.size(); i++)
    {
        pos[v[i]] = i;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != arr[i])
        {
            swaps++;
            int currPos = pos[arr[i]];
            pos[v[i]] = currPos;
            swap(v[currPos], v[i]);
        }
    }
    return swaps;
}
int minimumOperations(TreeNode *root)
{
    int count = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
            vec[i] = front->val;
        }
        count += minSwaps(vec);
    }
    return count;
}
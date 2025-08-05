#include<iostream>
using namespace std;

// REVERSE ODD LEVELS OF BINARY TREE (LEETCODE 2415)
// USING BFS TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Do a level-order traversal using a queue.
// 2. Track the current `level` starting from 0.
// 3. For **odd levels**, store all nodes in a vector `vec`.
// 4. After the level is complete, reverse the values of `vec` by swapping ends.
// 5. Continue to next level until the queue is empty.
// 6. Return the root of the modified tree.

TreeNode *reverseOddLevels(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        vector<TreeNode *> vec;
        for (int i = 0; i < n; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
            if (level % 2)
                vec.push_back(front);
        }
        if (level % 2)
        {
            int left = 0, right = n - 1;
            while (left <= right)
            {
                swap(vec[left]->val, vec[right]->val);
                left++, right--;
            }
        }
        level++;
    }
    return root;
}

// USING RECURSION - TC-O(N), SC=O(LOGN)
// Steps:
// 1. Perform DFS on the tree using symmetrical pairs (leftChild, rightChild).
// 2. Pass the current level (`level`) in recursion.
// 3. If the level is odd, swap the values of the symmetric pair.
// 4. Recursively call on the mirrored children:
//    - leftChild->left ↔ rightChild->right
//    - leftChild->right ↔ rightChild->left
// 5. Continue until all levels are processed.

void solve(TreeNode *leftChild, TreeNode *rightChild, int level)
{
    if (!leftChild || !rightChild)
        return;
    if (level % 2)
    {
        swap(leftChild->val, rightChild->val);
    }
    solve(leftChild->left, rightChild->right, !level);
    solve(leftChild->right, rightChild->left, !level);
}
TreeNode *reverseOddLevels(TreeNode *root)
{
    solve(root->left, root->right, 1);
    return root;
}
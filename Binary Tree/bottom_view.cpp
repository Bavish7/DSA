#include <iostream>
#include <vector>
using namespace std;

// BOTTOM VIEW OF BINARY TREE
// USING QUEUE - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Initialize an empty vector 'ans' to store the bottom view nodes.
// 2. If root is NULL, return 'ans'.
// 3. Initialize a map 'm' to store the horizontal distance (hd) and the node value at that distance.
// 4. Initialize a queue 'q' of pairs, where each pair contains a TreeNode<int>* and its horizontal distance.
// 5. Push the root node and its horizontal distance (0) into the queue.
// 6. While the queue is not empty:
//      a. Dequeue a pair 'temp' from the front of the queue.
//      b. Extract the current node 'curr' and its horizontal distance 'hd' from 'temp'.
//      c. Update the map 'm' with the current node's value at horizontal distance 'hd'.
//      d. If the left child of 'curr' exists, enqueue the left child with horizontal distance 'hd - 1'.
//      e. If the right child of 'curr' exists, enqueue the right child with horizontal distance 'hd + 1'.
// 7. Traverse the map 'm' and store the node values in 'ans' in the order of their horizontal distances.
// 8. Return 'ans', which contains the bottom view of the binary tree.

vector<int> bottomView(TreeNode<int> *root)
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
        m[hd] = curr->data;
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
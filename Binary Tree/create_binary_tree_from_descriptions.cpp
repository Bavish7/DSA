#include<iostream>
using namespace std;

// CREATE BINARY TREE FROM DESCRIPTIONS (LEETCODE 2196)
// USING UNORDERED MAP AND UNORDERED SET - TC=O(N), SC=O(N)

// Steps:
// 1. Use a map `mp` to create or access `TreeNode` objects for all values.
// 2. Use a set `st` to store all child nodes.
// 3. For each description:
//    - Ensure both parent and child nodes exist in the map.
//    - Link child to parent (left or right) based on `isLeft`.
//    - Mark child in the set.
// 4. The root is the only node not present in the child set.
// 5. Iterate through the map and return the node not in the child set.

TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
{
    unordered_map<int, TreeNode *> mp;
    unordered_set<int> st;
    for (auto des : descriptions)
    {
        if (mp.find(des[0]) == mp.end())
        {
            mp[des[0]] = new TreeNode(des[0]);
        }
        if (mp.find(des[1]) == mp.end())
        {
            mp[des[1]] = new TreeNode(des[1]);
        }
        if (des[2])
        {
            mp[des[0]]->left = mp[des[1]];
        }
        else
        {
            mp[des[0]]->right = mp[des[1]];
        }
        st.insert(des[1]);
    }
    for (auto &it : mp)
    {
        if (st.find(it.first) == st.end())
        {
            return it.second;
        }
    }
    return NULL;
}
#include<iostream>
using namespace std;

// SERIALIZE AND DESERIALIZE BINARY TREE (LEETCODE 297)
// USING LEVEL ORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// Serialization:
// 1. Use level-order traversal to convert the tree into a string representation.
// 2. Append each node's value to the string, separated by commas.
// 3. For `NULL` children, append `#` to represent missing nodes.
// 4. Return the final string after traversal is complete.

// Deserialization:
// 1. Use a queue to rebuild the tree in level-order.
// 2. Split the input string using commas as delimiters.
// 3. Create the root node using the first value and push it into the queue.
// 4. For each node in the queue, reconstruct its left and right children based on the next values in the string:
//    - If the value is `#`, set the corresponding child as `NULL`.
//    - Otherwise, create a new `TreeNode` and push it into the queue for further processing.
// 5. Return the reconstructed tree after all nodes are processed.

string serialize(TreeNode *root)
{
    if (!root)
        return "";
    string s = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
            s.append("#,");
        else
            s.append(to_string(curr->val) + ',');
        if (curr != NULL)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
        {
            curr->left = NULL;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(stoi(str));
            curr->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if (str == "#")
        {
            curr->right = NULL;
        }
        else
        {
            TreeNode *rightNode = new TreeNode(stoi(str));
            curr->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
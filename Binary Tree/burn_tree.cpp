#include <iostream>
#include <map>
using namespace std;

// TIME TO BURN TREE 
// USING QUEUE AND MAP - TC=O(N), SC=O(N)

// Steps:
// createMapping(root, start, nodeToParent):
// 1. Initialize a queue 'q' and add 'root' to it.
// 2. Create a mapping from each node to its parent in 'nodeToParent'.
// 3. Traverse the tree using BFS until the node with 'start' value is found.
// 4. Return the node with 'start' value.
//
// burnTree(root, nodeToParent):
// 1. Initialize a queue 'q' with 'root' and mark 'root' as visited.
// 2. Initialize 'visited' map to track visited nodes.
// 3. Initialize 'ans' to 0.
// 4. While 'q' is not empty:
//    a. For each level of nodes in 'q', check if any child node exists and is not visited.
//    b. If so, add child nodes to 'q' and mark them as visited.
//    c. Increment 'ans' if any nodes were added to 'q'.
// 5. Return 'ans', which represents the time taken for fire to reach all nodes from 'root'.
//
// timeToBurnTree(root, start):
// 1. Initialize 'nodeToParent' map to store parent-child relationships.
// 2. Find the node with 'start' value using createMapping function.
// 3. Calculate the time for fire to reach all nodes starting from 'start' using burnTree function.
// 4. Return the computed time.

BinaryTreeNode<int> *createMapping(BinaryTreeNode<int> *root, int start, map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &nodeToParent)
{
    BinaryTreeNode<int> *res = NULL;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front->data == start)
        {
            res = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int burnTree(BinaryTreeNode<int> *root, map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &nodeToParent)
{
    map<BinaryTreeNode<int> *, bool> visited;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}
int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> nodeToParent;
    BinaryTreeNode<int> *targetNode = createMapping(root, start, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}
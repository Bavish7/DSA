#include<iostream>
using namespace std;

// CHECK COMPLETENESS OF A BINARY TREE (LEETCODE 958)
// USING LEVEL ORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a queue and push the root node into it.
// 2. Perform a level order traversal of the tree:
//    - Dequeue a node from the front of the queue.
//    - If the dequeued node is NULL, mark that a null node has been found.
//    - If the dequeued node is not NULL:
//      - If a null node has already been found, the tree is not complete, return false.
//      - Enqueue the left and right children of the dequeued node into the queue.
// 3. If the traversal completes without finding a non-null node after a null node, the tree is complete, return true.

bool isCompleteTree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    bool nullFound = false;
    while (!q.empty())
    {
        TreeNode *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            nullFound = true;
        }
        else
        {
            if (nullFound == true)
            {
                return false;
            }
            q.push(frontNode->left);
            q.push(frontNode->right);
        }
    }
    return nullFound;
}
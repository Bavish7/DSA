#include<iostream>
using namespace std;

// POPULATING NEXT RIGHT POINTERS IN EACH NODE (LEETCODE 116)
// USING LEVEL ORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. If the tree is empty, return NULL.
// 2. Use a queue to perform level-order traversal.
// 3. Traverse each level and link nodes using the `next` pointer.
// 4. For each node, set `next` to the next node in the queue (except the last node in a level).
// 5. Enqueue the left and right children if they exist.
// 6. Return the modified tree with connected next pointers.

Node *connect(Node *root)
{
    if (root == NULL)
        return NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i != n - 1)
                curr->next = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return root;
}

// USING PREORDER TRAVERSAL - TC=O(N), SC=O(1)
// Steps:
// 1. If the tree is empty or has no children, return the root.
// 2. Connect the left child’s `next` pointer to the right child.
// 3. If the root has a `next` pointer, connect the right child’s `next` pointer to the left child of the root’s next node.
// 4. Recursively process the left and right subtrees.
// 5. Return the root after establishing all connections.

Node *connect(Node *root)
{
    if (root == NULL || root->left == NULL || root->right == NULL)
        return root;
    root->left->next = root->right;
    if (root->next != NULL)
    {
        root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
    return root;
}


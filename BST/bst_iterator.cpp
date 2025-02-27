#include<iostream>
using namespace std;

// BINARY SEARCH TREE ITERATOR (LEETCODE 173)
// USING STACK AND INORDER TRAVERSAL - TC=O(1) for next() and hasNext(), SC=O(H)

// Steps:
// 1. Use a stack to simulate an in-order traversal of a Binary Search Tree (BST).
// 2. Constructor (`BSTIterator`):
//    - Initialize by pushing all left nodes from the root into the stack (smallest values first).
// 3. `next()`:
//    - Retrieve the top node from the stack (current smallest value).
//    - Push all left nodes of its right child into the stack (to maintain in-order traversal).
//    - Return the value of the current node.
// 4. `hasNext()`:
//    - Check if the stack is non-empty, indicating more nodes to traverse.
// 5. Helper Function (`pushAll`):
//    - Push all left descendants of a node onto the stack to maintain traversal order.

stack<TreeNode *> st;
BSTIterator(TreeNode *root)
{
    pushAll(root);
}
int next()
{
    TreeNode *temp = st.top();
    st.pop();
    pushAll(temp->right);
    return temp->val;
}
bool hasNext()
{
    return !st.empty();
}
void pushAll(TreeNode *node)
{
    while (node)
    {
        st.push(node);
        node = node->left;
    }
}
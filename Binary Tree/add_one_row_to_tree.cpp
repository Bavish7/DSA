#include<iostream>
using namespace std;

// ADD ONE ROW TO TREE (LEETCODE 623)
// USING LEVEL ORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. If depth is 1, create a new root with value `val`, and set its left child as the original root.
// 2. Use BFS to traverse the tree level by level until reaching depth - 1.
// 3. At level = depth - 1:
//    - For each node at this level:
//       a. Create two new nodes with value `val`.
//       b. Set the original left child as the left child of the new left node.
//       c. Set the original right child as the right child of the new right node.
//       d. Assign the new nodes as the left and right children of the current node.
// 4. Return the modified root.

TreeNode *solve(TreeNode *root, int val, int depth){
    queue<TreeNode*>q;
    q.push(root);
    int level=1;
    while(!q.empty()){
        int n=q.size();
        if(level==depth-1){
            for(int i=0;i<n;i++){
                TreeNode *frontNode=q.front();
                q.pop();
                TreeNode *newLeft=new TreeNode(val);
                TreeNode *newRight=new TreeNode(val);
                newLeft->left=frontNode->left;
                newRight->right=frontNode->right;
                frontNode->left=newLeft;
                frontNode->right=newRight;
            }
            break;
        }
        for(int i=0;i<n;i++){
            TreeNode *frontNode=q.front();
            q.pop();
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
        }
        level++;
    }
    return root;
}
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(depth==1){
        TreeNode *newNode=new TreeNode(val);
        newNode->left=root;
        return newNode;
    }
    return solve(root,val,depth);
}
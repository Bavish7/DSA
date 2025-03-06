#include<iostream>
using namespace std;

// DELETE NODE IN A BST (LEETCODE 450)
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// maxValue(root):
// 1. Return NULL if root is NULL.
// 2. Initialize temp as root.
// 3. Traverse right subtree until reaching the maximum node.
// 4. Return temp, which now holds the maximum node.

// deleteNode(root, key):
// 1. Return NULL if root is NULL.
// 2. If root's value equals key:
//    - If root has no children, delete root and return NULL.
//    - If root has only left child, replace root with left child and delete root.
//    - If root has only right child, replace root with right child and delete root.
//    - If root has both children, find maximum value in left subtree, replace root's value with it,
//      and recursively delete the maximum node from the left subtree.
// 3. If key is less than root's value, recursively delete from the left subtree.
// 4. If key is greater than root's value, recursively delete from the right subtree.
// 5. Return root.

TreeNode *maxValue(TreeNode *root){
    if(root==NULL){
        return NULL;
    }
    TreeNode *temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}
TreeNode *deleteNode(TreeNode *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->val==key){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            TreeNode *child = root->left;
            delete root;
            return child;
        }
        else if(root->left==NULL && root->right!=NULL){
            TreeNode *child = root->right;
            delete root;
            return child;
        }
        else{
            TreeNode *leftMax = maxValue(root->left);
            root->val = leftMax->val;
            root->left=deleteNode(root->left, leftMax->val);
            return root;
        }
    }
    else if(root->val>key){
        root->left= deleteNode(root->left, key);
    }
    else{
        root->right=deleteNode(root->right, key);
    }
    return root;
}

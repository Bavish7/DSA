#include<iostream>
using namespace std;

// DELETE NODES AND RETURN FOREST (LEETCODE 1110)
// USING POSTORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Convert the `to_delete` list into a hash set for O(1) deletions.
// 2. Use post-order DFS to traverse and prune the tree:
//    - Recurse on left and right child first.
//    - If current node needs to be deleted:
//        - If it has non-null children, add them as new roots to `ans`.
//        - Return NULL to remove this node from its parent.
//    - Else, return the current node.
// 3. After traversal, if the root is not deleted, add it to the result.
// 4. Return the list of remaining tree roots after deletions.

TreeNode* solve(TreeNode *root, unordered_set<int>&st, vector<TreeNode*>& ans){
    if(!root) return NULL;
    root->left=solve(root->left,st,ans);
    root->right=solve(root->right,st,ans);
    if(st.find(root->val)!=st.end()){
        if(root->left){
            ans.push_back(root->left);
        }
        if(root->right){
            ans.push_back(root->right);
        }
        return NULL;
    }
    else return root; 
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*>ans;
    unordered_set<int>st;
    for(int &num: to_delete){
        st.insert(num);
    }
    solve(root,st,ans);
    if(st.find(root->val)==st.end()){
        ans.push_back(root);
    }
    return ans;
}

// USING LEVEL ORDER TRAVAERSAL - TC=O(N), SC=O(N)
// Steps:
// 1. Convert the `to_delete` list to a hash set for O(1) lookups.
// 2. Use BFS to traverse the tree level-by-level starting from root.
// 3. If the current node’s child is in the delete set:
//    - Push the child (if it exists) to the queue for further traversal.
//    - Disconnect the child from the current node.
// 4. If the current node is in the delete set:
//    - Add its non-null children to the answer vector (new tree roots).
// 5. After traversal, check if the root is not deleted. If so, add it to the result.
// 6. Return the list of remaining tree roots after deletions.

vector<TreeNode*> bfs(TreeNode *root, unordered_set<int>&st){
    if(!root) return {};
    vector<TreeNode*>ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode *currNode=q.front();
        q.pop();
        if(currNode->left){
            q.push(currNode->left);
            if(st.find(currNode->left->val)!=st.end()){
                currNode->left=NULL;
            }
        }
        if(currNode->right){
            q.push(currNode->right);
            if(st.find(currNode->right->val)!=st.end()){
                currNode->right=NULL;
            }
        }
        if(st.find(currNode->val)!=st.end()){
            if(currNode->left){
                ans.push_back(currNode->left);
            }
            if(currNode->right){
                ans.push_back(currNode->right);
            }
        }
    }
    return ans;
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    unordered_set<int>st;
    for(int &num: to_delete){
        st.insert(num);
    }
    vector<TreeNode*>ans=bfs(root,st);
    if(st.find(root->val)==st.end()){
        ans.push_back(root);
    }
    return ans;
}
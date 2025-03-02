#include<iostream>
using namespace std;

// INORDER PREDECESSOR OF NODE IN A BST
// USING COMPARISON - TC=O(N), SC=O(1)

// Steps : 
// 1. Initialize `pred` (predecessor)as NULL and set `curr` to the root of the tree.
// 2. Traverse the tree while `curr` is not NULL.
// 3. If the current node 's value is less than the target node `p`' s value, update `pred` to the current node(as it could be a predecessor) and move to the right subtree.
// 4. If the current node 's value is greater than or equal to `p`' s value, move to the left subtree(as the predecessor would be in the left side).
// 5. Once the traversal is complete, return the found predecessor.

Node * findPredecessor(Node * root, Node *p)
{
    Node *pred = NULL;
    Node *curr = root;
    while(curr){
        if(curr->data<p->data){
            pred = curr;
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return pred;
}

// INORDER SUCCESSOR OF NODE IN A BST
// USING COMPARISON - TC=O(N), SC=O(1)

// Steps :
// 1. Initialize `succ` (successor) as NULL and set `curr` to the root of the tree.
// 2. Traverse the tree while `curr` is not NULL.
// 3. If the current node 's value is greater than the target node `p`' s value, update `succ` to the current node(as it could be a successor) and move to the left subtree.
// 4. If the current node 's value is less than or equal to `p`' s value, move to the right subtree(as the successor would be in the right side).
// 5. Once the traversal is complete, return the found successor.

Node * findSuccessor(Node * root, Node *p)
{
    Node *succ = NULL;
    Node *curr = root;
    while(curr){
        if(curr->data>p->data){
            succ = curr;
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return succ;
}
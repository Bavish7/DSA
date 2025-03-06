#include<iostream>
#include<queue>
using namespace std;

// TC=O(N), SC=O(N)
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int value){
            this->data = value;
            this->left = NULL;
            this->right = NULL;
        }
};
Node *insertIntoBST(Node *root, int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    if(data>root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void levelOrderTraversalLevelWise(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
    }
}
void createBST(Node * &root){
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin >> data;
    }
}
bool searchInBST(Node *root, int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;
    if(root->data>target){
        leftAns= searchInBST(root->left, target);
    }
    else{
        rightAns= searchInBST(root->right, target);
    }
    return leftAns || rightAns;
}
int main(){
    Node *root = NULL;
    createBST(root);
    levelOrderTraversalLevelWise(root);
    int target;
    cout << "Enter the target: ";
    cin >> target;
    bool ans = searchInBST(root, target);
    if(ans){
        cout << "Found";
    }
}
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *createTree(){
    cout << "Enter the data: ";
    int data;
    cin >> data;
    if(data==-1){
        return NULL;
    }
    Node *root = new Node(data);
    cout << "Enter data for inserting in left of " << data<<endl;
    root->left = createTree();
    cout << "Enter data for inserting in right of " << data<<endl;
    root->right = createTree();
    return root;
}
void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *frontNode = q.front();
        q.pop();
        cout << frontNode->data<<" ";
        if(frontNode->left!=NULL){
            q.push(frontNode->left);
        }
        if(frontNode->right!=NULL){
            q.push(frontNode->right);
        }
    }
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
        if(frontNode==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
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
void buildFromLevelOrder(Node *&root){
    queue<Node *> q;
    cout << "Enter root data: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout << "Enter left Node for " << temp->data<<endl;
        int leftData;
        cin >> leftData;
        if(leftData!=-1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right Node for " << temp->data<<endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
void preOrderTraversal(Node *root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node *root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data<<" ";
}
void inOrderTraversal(Node *root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data<<" ";
    inOrderTraversal(root->right);
}

int main(){
    Node *root = NULL;
    // root = createTree();
    // 10 20 40 -1 -1 50 90 -1 -1 100 -1 -1 30 60 -1 -1 70 -1 -1
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // cout << endl;
    // levelOrderTraversalLevelWise(root);
    // preOrderTraversal(root);
    // cout << endl;
    // inOrderTraversal(root);
    // cout << endl;
    // postOrderTraversal(root);
    // cout << endl;
}
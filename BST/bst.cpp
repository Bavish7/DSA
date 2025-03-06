#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }

    // INSERTION IN BST
    Node* insert(Node *root, int data){
        if(root==NULL){
            return new Node(data);
        }
        else{
            Node *cur;
            if(data<= root->data){
                cur = insert(root->left, data);
                root->left = cur;
            }
            else{
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    // INORDER TRANVERSAL
    void inorder(Node *root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout << root->data<<" ";
        inorder(root->right);
    }

    // SEARCHING
    bool search(Node *root, int key){
        if(root==NULL || root->data==key){
            return true;
        }
        if(root->data<key){
            return search(root->right, key);
        }
        else{
            return search(root->left, key);
        }
    }

    // DELETING
    Node* deleteNode(Node *root, int k){
        if(root==NULL){
            return root;
        }
        if(root->data > k){
            root->left = deleteNode(root->left, k);
            return root;
        }
        else if(root->data <k){
            root->right = deleteNode(root->right, k);
            return root;
        }
        if(root->left==NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right== NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *parent = root;
            Node *succ = root->right;
            while(succ->left!=NULL){
                parent = succ;
                succ = succ->left;
            }
            if(parent!=root){
                parent->left = succ->left;
            }
            else{
                parent->right = succ->right;
            }
            root->data = succ->data;
            delete succ;
            return root;
        }
    } 
};
int main(){
    Node Tree(0);
    Node *root = NULL;
    cout << "Enter no. of elements: ";
    int t;
    cin >> t;
    cout << "Enter elements: ";
    while(t--){
        int data;
        cin >> data;
        root = Tree.insert(root, data);
    }
    Tree.inorder(root);
    cout << endl;
    cout << "Enter key to search: ";
    int key;
    cin >> key;
    if (Tree.search(root, key))
    {
        cout << "Value " << key << " is present in the tree." << endl;
    }
    else
    {
        cout << "Value " << key << " is not present in the tree." << endl;
    }
}

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        ~Node(){
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
        }
};
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail,int data){
    Node *newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtPos(Node *&head, Node *&tail, int data, int pos){
    if(pos==1){
        insertAtHead(head, tail, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(head, tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(Node *&head, Node *&tail, int pos){
    if(pos==1){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while(count<pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        if(prev->next==NULL){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    Node *n1 = new Node(10);
    Node *head = n1;
    Node *tail = n1;
    insertAtHead(head, tail, 12);
    insertAtTail(head, tail, 8);
    insertAtPos(head, tail, 6, 3);
    deleteNode (head, tail,4);
    cout << tail->data<<endl;
    print(head);
}


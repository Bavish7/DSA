#include<iostream>
using namespace std;

// IMPLEMENT STACK USING LINKED LIST - TC=O(1), SC=O(N)
class Stack
{
    Node *head = NULL;
    int size = 0;

public:
    Stack()
    {
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        size++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    int getTop()
    {
        if (!isEmpty())
        {
            return head->data;
        }
        return -1;
    }
};
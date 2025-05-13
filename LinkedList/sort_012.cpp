#include<iostream>
using namespace std;

// SORT 012
// USING ITERATION AND COUNTING - TC=O(N), SC=O(1)

// Steps:
// 1. Count Occurrences: Traverse the list to count occurrences of 0s, 1s, and 2s.
// 2. Update Values: Traverse the list again and update the values based on the counts obtained.

Node *sortList(Node *head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

// MERGING SEPARATE LINKED LISTS - TC=O(N), SC=O(1)
// Steps:
// 1. Create three dummy nodes to represent the heads of three separate lists: one for 0s, one for 1s, and one for 2s.
// 2. Traverse the original list and append nodes to the appropriate list (0s, 1s, or 2s) based on their value.
// 3. Merge the three lists:
//    - Connect the tail of the 0s list to the head of the 1s list. If the 1s list is empty, connect to the 2s list instead.
//    - Connect the tail of the 1s list to the head of the 2s list.
//    - Ensure the tail of the 2s list points to NULL to terminate the list.
// 4. Update the head of the original list to point to the new sorted list.
// 5. Delete the dummy nodes used for merging to avoid memory leaks.

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    Node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}
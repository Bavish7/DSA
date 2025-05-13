#include<iostream>
using namespace std;

// ROTATE LIST(LEETCODE 61)
// USING ITERATION - TC=O(N), SC=O(1)

// Steps:
// 1. Calculate Length: Determine the length of the list.
// 2. Adjust k: Use modulo operation to handle cases where k is larger than the length of the list.
// 3. Find the Tail: Locate the end of the list and connect it to the head to make it circular.
// 4. Find the New Tail: Determine the new tail position based on the adjusted k value.
// 5. Break the Circular Connection: Set the next of the new tail to NULL and update the head.

int getLength(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head)
    {
        return NULL;
    }
    int len = getLength(head);
    k = k % len;
    if (k == 0)
    {
        return head;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    int rotatePos = len - k - 1;
    ListNode *newNode = head;
    for (int i = 0; i < rotatePos; i++)
    {
        newNode = newNode->next;
    }
    head = newNode->next;
    newNode->next = NULL;
    return head;
}
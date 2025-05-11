#include<iostream>
using namespace std;

// REMOVE LOOP FROM LINKED LIST
// USING TWO POINTERS (FLOYD'S CYCLE DETECTION ALGORITHM) - TC=O(N), SC=O(1)

// Steps:
// 1. **Detect Cycle:** Use two pointers (slow and fast) to detect a cycle in the list.
// 2. **Find Cycle Start:** Once a cycle is detected, move one pointer to the head and another to the meeting point.
// 3. **Locate Loop Start:** Traverse the list to find the start of the loop.
// 4. **Remove Loop:** Adjust the next pointer of the last node in the loop to NULL.

void *removeLoop(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            break;
        }
    }
    if (fast == NULL)
    {
        return fast;
    }
    slow = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *start = slow;
    ListNode *temp = fast;
    while(temp->next!=start){
        temp = temp->next;
    }
    temp->next = NULL;
}
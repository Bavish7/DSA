#include<iostream>
using namespace std;

// REMOVE NTH NODE FROM THE END OF THE LIST(LEETCODE 19)
// FINDING LENGTH AND REMOVING - TC=O(N), SC=O(1)

// Steps:
// 1. **Find Length:** Compute the total length of the linked list.
// 2. **Edge Cases:** Handle cases where the node to remove is the head or when there's only one node.
// 3. **Traverse to Target:** Traverse to the node just before the one to be removed.
// 4. **Remove Node:** Adjust pointers to remove the target node.

int getLength(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int len = getLength(head);
    if (len == 1)
    {
        return NULL;
    }
    if (len == n)
    {
        return head->next;
    }
    int count = 0;
    ListNode *temp = head;
    while (count < len - n - 1)
    {
        temp = temp->next;
        count++;
    }
    temp->next = temp->next->next;
    return head;
}
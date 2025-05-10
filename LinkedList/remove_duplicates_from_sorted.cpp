#include<iostream>
using namespace std;

// REMOVE DUPLICATES FROM SORTED LIST(LEETCODE 83)
// USING ITERATION - TC=O(N), SC=O(1)

// Steps:
// 1. **Edge Case Handling:** If the list is empty or has only one node, return it as-is.
// 2. **Iterate Through List:** Use a pointer to traverse the list.
// 3. **Check for Duplicates:** For each node, if the next node has the same value, remove the next node.
// 4. **Update Pointer:** Move to the next node if no duplicate is found.

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->val == temp->next->val)
        {
            ListNode *newNode = temp->next;
            temp->next = newNode->next;
            newNode->next = NULL;
            delete newNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
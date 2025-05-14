#include<iostream>
using namespace std;

// SWAPPING NODES IN A LINKED LIST (LEETCODE 1721)
// USING RECURSION AND BREAKING THE LINKS - TC=O(N), SC=O(N)

// Steps:
// 1. Get the length of the linked list using a recursive helper function.
// 2. Determine the positions of the nodes to swap based on the value of k and the length of the list.
// 3. If the positions are the same, return the head as no swap is needed.
// 4. Handle edge cases such as swapping nodes at the start and end or when the list has only two nodes.
// 5. Traverse the list to reach the nodes at lPos and rPos.
// 6. Perform the swap by adjusting pointers without actually moving node data.
// 7. Return the modified head of the linked list.

int getLength(ListNode *head)
{
    if (!head)
        return 0;
    return 1 + getLength(head->next);
}
ListNode *swapNodes(ListNode *head, int k)
{
    if (!head || !head->next)
        return head;
    int len = getLength(head);
    int lPos = k;
    int rPos = len - k + 1;
    if (rPos < lPos)
    {
        swap(lPos, rPos);
    }
    if (lPos == rPos)
        return head;
    if (len == 2)
    {
        ListNode *nextNode = head->next;
        nextNode->next = head;
        head->next = NULL;
        head = nextNode;
        return head;
    }
    if (lPos == 1)
    {
        ListNode *lPtr = NULL;
        ListNode *lNode = head;
        ListNode *rPtr = head;
        for (int i = 0; i < rPos - 2; i++)
        {
            rPtr = rPtr->next;
        }
        ListNode *rNode = rPtr->next;
        ListNode *rSave = rNode->next;
        rNode->next = lNode->next;
        rPtr->next = lNode;
        lNode->next = rSave;
        head = rNode;
        return head;
    }
    int noOfNodes = rPos - lPos - 1;
    if (noOfNodes == 0)
    {
        ListNode *lPtr = head;
        for (int i = 0; i < lPos - 2; i++)
        {
            lPtr = lPtr->next;
        }
        ListNode *lNode = lPtr->next;
        ListNode *rPtr = head;
        for (int i = 0; i < rPos - 2; i++)
        {
            rPtr = rPtr->next;
        }
        ListNode *rNode = rPtr->next;
        ListNode *rSave = rNode->next;
        lPtr->next = rPtr->next;
        rNode->next = rPtr;
        rPtr->next = rSave;
        return head;
    }
    else
    {
        ListNode *lPtr = head;
        for (int i = 0; i < lPos - 2; i++)
        {
            lPtr = lPtr->next;
        }
        ListNode *lNode = lPtr->next;
        ListNode *rPtr = head;
        for (int i = 0; i < rPos - 2; i++)
        {
            rPtr = rPtr->next;
        }
        ListNode *rNode = rPtr->next;
        ListNode *rSave = rNode->next;
        lPtr->next = rNode;
        rNode->next = lNode->next;
        rPtr->next = lNode;
        lNode->next = rSave;
        return head;
    }
}
#include<iostream>
using namespace std;

// INTERSECTION OF TWO LINKED LISTS (LEETCODE 160)
// FINDING LENGTH AND EQUALING TWO LINKED LISTS - TC=O(MAX(M,N)), SC=O(1)

// Steps:
// 1. Define a helper function `getLength` to compute the length of a linked list.
//    - Traverse through the linked list to count the number of nodes and return the length.
// 2. In `getIntersectionNode` function:
//    - Compute the lengths of both linked lists `headA` and `headB` using the `getLength` function.
//    - Calculate the difference in lengths between the two lists.
//    - Advance the pointer of the longer list by the difference in lengths so that both pointers are equidistant from the end of their respective lists.
//    - Traverse both lists simultaneously and compare nodes. If nodes are equal, return the intersecting node.
//    - If no intersection is found, return NULL.

int getLength(ListNode *head)
{
    ListNode *temp = head;
    int len = 1;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    int l1 = getLength(temp1);
    int l2 = getLength(temp2);
    int diff = abs(l1 - l2);
    if (l1 > l2)
    {
        while (diff > 0)
        {
            temp1 = temp1->next;
            diff--;
        }
    }
    else
    {
        while (diff > 0)
        {
            temp2 = temp2->next;
            diff--;
        }
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}
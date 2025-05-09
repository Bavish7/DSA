#include<iostream>
using namespace std;

// MERGE TWO SORTED LISTS(LEETCODE 21)
// CREATING NEW LINKED LIST AND PUTTING THE LOWER VALUES. TC=O(N), SC=O(1)

// Steps:
// 1. **Initialize Pointers:** Create a dummy node to act as the starting point of the new merged list.
// 2. **Compare Nodes:** Iterate through both lists, comparing the current nodes from each list and attaching the smaller node to the new list.
// 3. **Attach Remaining Nodes:** Once one list is exhausted, attach the remaining nodes of the other list to the merged list.

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    ListNode *ans = new ListNode(-1);
    ListNode *ptr = ans;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            ptr->next = list1;
            ptr = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            ptr = list2;
            list2 = list2->next;
        }
    }
    if (list1 != NULL)
    {
        ptr->next = list1;
    }
    if (list2 != NULL)
    {
        ptr->next = list2;
    }
    return ans->next;
}
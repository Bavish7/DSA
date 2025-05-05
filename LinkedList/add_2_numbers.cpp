#include<iostream>
using namespace std;

// ADD TWO NUMBERS(LEETCODE 2)
// APPROACH - TC=O(MAX(L1,L2)), SC=O(MAX(L1,L2))

// Steps:
// 1. Initialize a dummy node to build the result list and a `temp` pointer to keep track of the end of the result list.
//    - Initialize `carry` to 0 to handle the carry-over during addition.
// 2. Iterate while either of the input lists or the carry is not zero:
//    - Initialize `sum` to 0 for each iteration.
//    - Add the value of the current node from `l1` if `l1` is not NULL and move `l1` to the next node.
//    - Add the value of the current node from `l2` if `l2` is not NULL and move `l2` to the next node.
//    - Add `carry` to the sum and calculate the new carry (`carry = sum / 10`).
//    - Create a new node with the value of `sum % 10` and append it to the result list.
//    - Move `temp` to the newly created node.
// 3. Return `dummy->next` as the head of the result list, which excludes the initial dummy node.

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode *newnode = new ListNode(sum % 10);
        temp->next = newnode;
        temp = temp->next;
    }
    return dummy->next;
}
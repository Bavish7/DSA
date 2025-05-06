#include<iostream>
using namespace std;

// DOUBLE A NUMBER REPRESENTED AS A LINKED LIST (LEETCODE 2816)
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Recursively traverse to the end of the list with the solve function.
// 2. Multiply each node's value by 2 and add the carry from the previous operation.
// 3. Update the node's value to prod % 10 and update carry to prod / 10.
// 4. After recursion, if carry is not 0, create a new node with carry as its value and set it as the new head.
// 5. Return the head of the modified list.

void solve(ListNode *head, int &carry)
{
    if (!head)
        return;
    solve(head->next, carry);
    int prod = head->val * 2 + carry;
    head->val = prod % 10;
    carry = prod / 10;
}
ListNode *doubleIt(ListNode *head)
{
    int carry = 0;
    solve(head, carry);
    if (carry != 0)
    {
        ListNode *newNode = new ListNode(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
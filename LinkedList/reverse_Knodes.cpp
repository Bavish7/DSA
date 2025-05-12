#include <iostream>
using namespace std;

// REVERSE NODES IN K-GROUP(LEETCODE 25)
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Check Length: If the length of the list is less than k, no need to reverse.
// 2. Reverse K Nodes: Reverse the first k nodes.
// 3. Recursion: Recursively reverse the rest of the list and attach it to the reversed part.
// 4. Return New Head: Return the new head of the reversed list.

int getLength(ListNode *head){
    ListNode *temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
ListNode *reverseKGroup(ListNode *head, int k){
    int len = getLength(head);
    if(len<k){
        return head;
    }
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *newNode = NULL;
    int pos = 0;
    while(pos<k){
        newNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = newNode;
        pos++;
    }
    if(newNode!=NULL){
        head->next = reverseKGroup(newNode, k);
    }
    return prev;
}
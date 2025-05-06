#include<iostream>
using namespace std;

// COPY LIST WITH RANDOM POINTER(LEETCODE 138)
// USING MAP AND RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Use a recursive function `solve` to create a copy of the linked list.
//    - `solve` takes the current node (`head`) and a map (`mp`) to keep track of the original-to-new node mapping.
//    - If the current node is NULL, return NULL (base case).
//    - Create a new node with the same value as the current node.
//    - Store the mapping of the original node to the new node in the map.
//    - Recursively copy the next node and assign it to the `next` pointer of the new node.
//    - If the original node has a random pointer, set the `random` pointer of the new node using the map.
// 2. Call the `solve` function from `copyRandomList` with the initial head of the list and an empty map.

Node *solve(Node *&head, unordered_map<Node *, Node *> &mp)
{
    if (!head)
    {
        return NULL;
    }
    Node *newHead = new Node(head->val);
    mp[head] = newHead;
    newHead->next = solve(head->next, mp);
    if (head->random)
    {
        newHead->random = mp[head->random];
    }
    return newHead;
}
Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp;
    return solve(head, mp);
}

// WITHOUT USING MAP - TC=O(N), SC=O(1)
Node *solve(Node *head){
    if(!head){
        return NULL;
    }
    Node *original = head;
    while(original!=NULL){
        Node *clone = new Node(original->val);
        clone->next = original->next;
        original->next = clone;
        original = clone->next;
    }
    original = head;
    while(original!=NULL){
        Node *clone = original->next;
        clone->random = original->random ? original->random->next : NULL;
        original = clone->next;
    }
    original = head;
    Node *cloneHead = original->next;
    while(original!=NULL){
        Node *clone = original->next;
        original->next = clone->next;
        if(clone->next){
            clone->next = clone->next->next;
        }
        original = original->next;
    }
    return cloneHead;
}
Node *copyRandomList(Node *head){
    return solve(head);
}

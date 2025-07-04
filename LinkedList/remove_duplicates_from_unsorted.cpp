#include<iostream>
using namespace std;

// REMOVE DUPLICATES FROM UNSORTED LINKED LIST(LEETCODE 1836)
// USING UNORDERED MAP - TC=O(N), SC=O(N)

// Steps:
// 1. **Initialize Map:** Create an unordered map to keep track of seen values.
// 2. **Traverse List:** Use a pointer to traverse the list and another to keep track of the previous node.
// 3. **Check for Duplicates:** For each node, check if its value is in the map. If not, add it to the map.
// 4. **Remove Duplicates:** If a duplicate is found, adjust the previous node's next pointer and delete the duplicate node.
// 5. **Update Pointers:** Move to the next node.

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    unordered_map<int, bool> visited;
    while (temp != NULL)
    {
        if (visited[temp->data] == false)
        {
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
        else
        {
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
        temp = prev->next;
    }
    return head;
}
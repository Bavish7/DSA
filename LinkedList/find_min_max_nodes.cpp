#include<iostream>
using namespace std;

// FIND THE MIN AND MAX NO. OF NODES BETWEEN CRITICAL POINTS (LEETCODE 2058)
// USING LINKED LIST - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize pointers prev to head, curr to the second node, and nxt to the third node.
// 2. If any of the pointers prev, curr, or nxt is NULL, return {-1, -1} because there aren't enough nodes for critical points.
// 3. Initialize variables i (index) to 1, firstCP and lastCP to -1 (to track the first and last critical points), and minDist to INT_MAX.
// 4. Traverse the list while nxt is not NULL:
//    - Check if the current node (curr) is a critical point (either a local maximum or minimum) by comparing it with prev and nxt.
//    - If curr is a critical point and firstCP is -1, set firstCP and lastCP to i.
//    - If curr is a critical point and firstCP is not -1, update minDist with the minimum distance between the current and last critical points, and set lastCP to i.
//    - Move prev to curr, curr to nxt, and nxt to nxt->next. Increment i.
// 5. If lastCP equals firstCP, return {-1, -1} because only one critical point was found.
// 6. Otherwise, return {minDist, lastCP - firstCP} representing the minimum and maximum distances between critical points.

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    ListNode *prev = head;
    ListNode *curr = head->next;
    ListNode *nxt = head->next->next;
    if (!prev || !curr || !nxt)
    {
        return {-1, -1};
    }
    int i = 1;
    int firstCP = -1, lastCP = -1;
    int minDist = INT_MAX;
    while (nxt)
    {
        bool isCP = false;
        if ((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val))
        {
            isCP = true;
        }
        if (isCP && firstCP == -1)
        {
            firstCP = i;
            lastCP = i;
        }
        else if (isCP)
        {
            minDist = min(minDist, i - lastCP);
            lastCP = i;
        }
        i++;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    if (lastCP == firstCP)
    {
        return {-1, -1};
    }
    else
    {
        return {minDist, lastCP - firstCP};
    }
}
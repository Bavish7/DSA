#include<iostream>
using namespace std;

// ASTEROID COLLISION (LEETCODE 735)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. For each asteroid in the array:
//    - If the stack is empty or the asteroid is moving right, push it to the stack.
//    - If the asteroid is moving left, check the top of the stack:
//      - If the top asteroid is moving right, a collision occurs.
//      - Compare the size of both asteroids and pop the stack if the top asteroid is smaller.
//      - If they are equal in size, both explode (pop the stack and skip the current asteroid).
//      - If the top asteroid is larger, the current asteroid is destroyed.
// 2. Once all asteroids are processed, collect the surviving asteroids from the stack.
// 3. Reverse the stack to get the final result.

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    for (int i = 0; i < asteroids.size(); i++)
    {
        bool exploded = false;
        while (!st.empty() && asteroids[i] < 0 && st.top() > 0)
        {
            if (abs(asteroids[i]) > abs(st.top()))
            {
                st.pop();
            }
            else if (asteroids[i] + st.top() == 0)
            {
                st.pop();
                exploded = true;
                break;
            }
            else
            {
                exploded = true;
                break;
            }
        }
        if (!exploded)
        {
            st.push(asteroids[i]);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
#include<iostream>
using namespace std;

// CAR FLEET (LEETCODE 853)
// USING STACK AND SORTING - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Create a vector of pairs where each pair contains the position and time taken to reach the target for each car.
// 2. Sort the cars by their position in ascending order.
// 3. Use a stack to determine the number of car fleets:
//    - Iterate from the last car to the first.
//    - If the current car's time to reach the target is greater than the time on the top of the stack, it forms a new fleet, so push this time onto the stack.
//    - If the current car's time is less than or equal to the top of the stack, it joins an existing fleet.
// 4. The size of the stack represents the number of car fleets.
// 5. Return the size of the stack.

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int n = position.size();
    vector<pair<int, double>> cars(n);
    for (int i = 0; i < n; i++)
    {
        cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
    }
    sort(cars.begin(), cars.end());
    stack<double> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty() || cars[i].second > st.top())
        {
            st.push(cars[i].second);
        }
    }
    return st.size();
}

// CAR FLEET II (LEETCODE 1776)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a result vector 'ans' of size equal to the number of cars, filled with -1 (indicating no collision yet).
// 2. Use a stack to store indices of cars that could potentially collide.
// 3. Iterate from the last car to the first:
//    - For each car, pop the stack if the speed of the top car in the stack is less than or equal to the current car (as it will never collide).
//    - Calculate the collision time with the car at the top of the stack if a collision is possible:
//      - If the calculated collision time is smaller than or equal to the collision time of the car at the top, set the collision time for the current car.
//      - If not, continue popping the stack.
// 4. Push the current car's index onto the stack for future comparisons.
// 5. Return the result vector 'ans' which contains the collision times.

vector<double> getCollisionTimes(vector<vector<int>> &cars)
{
    vector<double> ans(cars.size(), -1);
    stack<int> st;
    for (int i = cars.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && cars[st.top()][1] >= cars[i][1])
        {
            st.pop();
        }
        while (!st.empty())
        {
            double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
            if (ans[st.top()] == -1 || colTime <= ans[st.top()])
            {
                ans[i] = colTime;
                break;
            }
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
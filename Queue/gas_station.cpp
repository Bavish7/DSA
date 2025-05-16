#include <iostream>
#include <queue>
using namespace std;

// GAS STATION (LEETCODE 134) 
// USING GREEDY APPROACH - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize `deficit` to keep track of the total deficit of gas when the balance goes negative.
// 2. Initialize `balance` to keep track of the current balance of gas as we traverse the stations.
// 3. Initialize `start` to store the index of the starting gas station from which the circuit can be completed.
// 4. Traverse through all gas stations:
//    - Update the `balance` by adding the difference between gas available and cost to travel to the next station.
//    - If `balance` becomes negative, it means we cannot complete the circuit starting from the current `start` index.
//      - Add the negative balance to `deficit` and update `start` to the next station (i + 1).
//      - Reset `balance` to 0.
// 5. After completing the traversal, check if the total gas available (`deficit + balance`) is sufficient to cover the total cost:
//    - If yes, return the starting index `start`.
//    - Otherwise, return -1, indicating that completing the circuit is not possible.

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        balance += gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}
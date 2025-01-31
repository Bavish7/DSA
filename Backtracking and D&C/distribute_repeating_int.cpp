#include<iostream>
using namespace std;

// DISTRIBUTE REPEATING INTEGERS (LEETCODE 1655)
// USING RECURSION AND BACKTRACKING - TC=O(M*N), SC=O(N)

// Steps:
// 1. Base case: If all customers have been served (customer equals quantity size), return true.
// 2. Loop through each count in countArray and check if it can satisfy the current customer's quantity requirement.
// 3. If valid, reduce the count in countArray by the quantity needed, recursively try to serve the next customer, and if successful, return true.
// 4. If the recursive call fails, backtrack by restoring the original count in countArray.
// 5. If no valid assignment is found, return false.
// 6. In the canDistribute function, count the occurrences of each number in nums, store these counts in a vector, and sort the quantity array in descending order.
// 7. Call the recursive solve function to determine if distribution is possible.

bool solve(vector<int> &countArray, vector<int> &quantity, int customer)
{
    if (customer == quantity.size())
    {
        return true;
    }
    for (int i = 0; i < countArray.size(); i++)
    {
        if (countArray[i] >= quantity[customer])
        {
            countArray[i] -= quantity[customer];
            if (solve(countArray, quantity, customer + 1))
            {
                return true;
            }
            countArray[i] += quantity[customer];
        }
    }
    return false;
}
bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    unordered_map<int, int> countMap;
    for (auto num : nums)
    {
        countMap[num]++;
    }
    vector<int> counts;
    for (auto it : countMap)
    {
        counts.push_back(it.second);
    }
    sort(quantity.rbegin(), quantity.rend());
    return solve(counts, quantity, 0);
}
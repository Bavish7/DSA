#include<iostream>
using namespace std;

// BEST TIME TO BUT AND SELL STOCK (LEETCODE 121)
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Use a recursive function `maxProfitFinder` to iterate through the prices array.
// 2. At each step, update the minimum price encountered so far.
// 3. Calculate today's profit by subtracting the minimum price from the current price.
// 4. Update the maximum profit if today's profit is greater than the current maximum profit.
// 5. Continue the recursion until all prices are checked.
// 6. Return the maximum profit obtained.

void maxProfitFinder(vector<int> &prices, int i, int &minPrice, int &maxProfit)
{
    if (i == prices.size())
    {
        return;
    }
    if (prices[i] < minPrice)
    {
        minPrice = prices[i];
    }
    int todaysProfit = prices[i] - minPrice;
    if (todaysProfit > maxProfit)
    {
        maxProfit = todaysProfit;
    }
    maxProfitFinder(prices, i + 1, minPrice, maxProfit);
}
int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}
#include<iostream>
using namespace std;

// ONLINE STOCK SPAN (LEETCODE 901)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a stack to store pairs of (price, span).
// 2. For each new price, initialize the span as 1.
// 3. While the stack is not empty and the top price in the stack is less than or equal to the current price:
//    - Add the top span to the current span.
//    - Pop the top element from the stack.
// 4. Push the current price and its span onto the stack.
// 5. Return the current span.

stack<pair<int, int>> st;
StockSpanner()
{
}
int next(int price)
{
    int span = 1;
    while (!st.empty() && st.top().first <= price)
    {
        span += st.top().second;
        st.pop();
    }
    st.push({price, span});
    return span;
}
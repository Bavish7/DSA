#include<iostream>
using namespace std;

// GENERATE PARENTHESES (LEETCODE 22)
// USING RECURSION AND BACKTRACKING - TC=O(4^N/sqrt(N)), SC=O(4^N/sqrt(N))

// Steps:
// 1. The problem is to generate all valid combinations of `n` pairs of parentheses.
// 2. Use a recursive backtracking approach to explore all possible combinations.
// 3. Maintain two counters `open` and `close` to track the number of open and close parentheses added so far:
//    - If the length of the current string `curr` reaches `2 * n`, it means we have a valid combination, so add it to the result.
//    - If the `open` counter is less than `n`, add an open parenthesis and recurse.
//    - If the `close` counter is less than the `open` counter, add a close parenthesis and recurse.
// 4. Base case is when `curr` reaches a length of `2 * n`.
// 5. The recursion ensures all valid combinations are generated without duplicates.

void generateParenthesis(string curr, int open, int close, int n, vector<string> &result)
{
    if (curr.length() == 2 * n)
    {
        result.push_back(curr);
        return;
    }
    if (open < n)
    {
        generateParenthesis(curr + '(', open + 1, close, n, result);
    }
    if (close < open)
    {
        generateParenthesis(curr + ')', open, close + 1, n, result);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    generateParenthesis("", 0, 0, n, result);
    return result;
}
#include<iostream>
using namespace std;

// EXPRESSION ADD OPERATORS (LEETCODE 282)
// USING BACKTRACKING - TC=O(4^N), SC=O(N)

// Steps:
// 1. The problem is to add operators (+, -, *) between the digits of a string `num` to form a target value `target`.
// 2. Use a recursive backtracking approach to explore all possible combinations of operators.
// 3. Maintain a few variables to keep track of the current expression, the current value, and the previous operand:
//    - `expr` stores the current expression formed by adding operators between the digits.
//    - `val` stores the current value of the expression.
//    - `prev` stores the previous operand to handle multiplication.
// 4. Start by exploring all possible splits of the input string `num`:
//    - For each split, convert the substring to a number and add it to the expression.
//    - For each number, explore all possible operators (+, -, *) to add between the digits.
// 5. The base case is when the entire string `num` is processed, and the current value equals the target value.
// 6. The recursion ensures all possible combinations are explored to reach the target value.

void backtrack(string num, int target, int index, long long val, long long prev, string expr, vector<string> &result)
{
    if (index == num.length())
    {
        if (val == target)
        {
            result.push_back(expr);
        }
        return;
    }
    for (int i = index; i < num.length(); i++)
    {
        if (i != index && num[index] == '0')
        {
            break;
        }
        long long curr = stoll(num.substr(index, i - index + 1));
        if (index == 0)
        {
            backtrack(num, target, i + 1, curr, curr, expr + to_string(curr), result);
        }
        else
        {
            backtrack(num, target, i + 1, val + curr, curr, expr + "+" + to_string(curr), result);
            backtrack(num, target, i + 1, val - curr, -curr, expr + "-" + to_string(curr), result);
            backtrack(num, target, i + 1, val - prev + prev * curr, prev * curr, expr + "*" + to_string(curr), result);
        }
    }
}
vector<string> addOperators(string num, int target)
{
    vector<string> result;
    backtrack(num, target, 0, 0, 0, "", result);
    return result;
}

// OPTIMAL APPROACH
// USING BACKTRACKING - TC=O(4^N), SC=O(N)

// Steps:
// 1. The problem is to add operators (+, -, *) between the digits of a string `num` to form a target value `target`.
// 2. Use a recursive backtracking approach to explore all possible combinations of operators.
// 3. Maintain a few variables to keep track of the current expression, the current value, and the previous operand:
//    - `expr` stores the current expression formed by adding operators between the digits.
//    - `val` stores the current value of the expression.
//    - `prev` stores the previous operand to handle multiplication.
// 4. Start by exploring all possible splits of the input string `num`:
//    - For each split, convert the substring to a number and add it to the expression.
//    - For each number, explore all possible operators (+, -, *) to add between the digits.
// 5. The base case is when the entire string `num` is processed, and the current value equals the target value.
// 6. The recursion ensures all possible combinations are explored to reach the target value.


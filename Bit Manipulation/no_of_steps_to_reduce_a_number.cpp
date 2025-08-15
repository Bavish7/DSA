#include<iostream>
using namespace std;

// NUMBER OF STEPS TO REDUCE A NUMBER IN BINARY REPRESENTATION OF ONE (LEETCODE 1404)
// USING STRING MANIPULATION - TC=O(N^2), SC=O(1)

// Steps:
// 1. While binary string length > 1:
//    - If last bit is '0', remove it (binary division by 2).
//    - If last bit is '1', call `addOne()` to increment the binary number.
// 2. `addOne()`:
//    - Traverse from last bit backwards until finding a '0'.
//    - Turn all trailing '1's to '0's, then set first '0' found to '1'.
//    - If no '0' found (all '1's), prepend '1' to the string.
// 3. Increment step count for each operation.
// 4. Return total steps.

void addOne(string &s)
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] != '0')
    {
        s[i] = '0';
        i--;
    }
    if (i < 0)
    {
        s = '1' + s;
    }
    else
    {
        s[i] = '1';
    }
}
int numSteps(string s)
{
    int steps = 0;
    while (s.size() > 1)
    {
        int n = s.size();
        if (s[n - 1] == '0')
            s.pop_back();
        else
        {
            addOne(s);
        }
        steps++;
    }
    return steps;
}

// USING BIT MANIPULATION - TC=O(N), SC=O(1)
// Steps:
// 1. Iterate from the last bit to the second bit (index 1):
//    - If the current bit + carry is odd → we need:
//        a) Add 1 (which turns it even) → 1 step
//        b) Divide by 2 (right shift) → another step
//      → Hence, steps += 2 and carry becomes 1.
//    - If the current bit + carry is even → just divide by 2 → steps += 1.
// 2. After loop, if carry is still 1, add 1 more step to handle overflow.
// 3. Return total steps.

int numSteps(string s)
{
    int n = s.size();
    int steps = 0;
    int carry = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (((s[i] - '0') + carry) % 2 == 1)
        {
            steps += 2;
            carry = 1;
        }
        else
        {
            steps++;
        }
    }
    return steps + carry;
}
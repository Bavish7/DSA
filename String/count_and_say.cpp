#include<iostream>
using namespace std;

// COUNT AND SAY (LEETCODE 38)
// USING ITERATION - TC=O(N*MAXLEN), SC=O(MAXLEN)

// Steps:
// 1. Initialize the result string `out` with "1" for the first sequence.
// 2. Repeat the process `n - 1` times to build subsequent sequences:
//    - Start with an empty string `str`.
//    - Traverse the current sequence `out` and count consecutive identical characters:
//      - If the character matches `prevChar`, increment the count.
//      - Otherwise, append the count and character to `str`, update `prevChar`, and reset the count.
//    - Append the final count and character after exiting the loop.
//    - Update `out` to `str` for the next iteration.
// 3. Return the final result after building `n` sequences.

string countAndSay(int n)
{
    string out = "1";
    for (int i = 0; i < n - 1; i++)
    {
        string str = "";
        char prevChar = out[0];
        int count = 1;
        for (int j = 1; j < out.length(); j++)
        {
            if (out[j] == prevChar)
            {
                count++;
            }
            else
            {
                str += to_string(count) + prevChar;
                prevChar = out[j];
                count = 1;
            }
        }
        str += to_string(count) + prevChar;
        out = str;
    }
    return out;
}
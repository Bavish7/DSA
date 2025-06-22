#include<iostream>
using namespace std;

// COMPARE VERSION STRINGS (LEETCODE 165)
// USING TWO POINTERS - TC=O(MAX(M,N)), SC=O(1)

// Steps:
// 1. Initialize pointers `i` and `j` to traverse `version1` and `version2`, respectively.
// 2. Loop until both `i < n1` or `j < n2`:
//    - Parse the integer between the current position and the next dot (`.`) for both strings:
//      - Multiply the previous number by 10 and add the digit to build the integer.
//    - Compare the parsed numbers `num1` and `num2`:
//      - Return `1` if `num1 > num2`, `-1` if `num1 < num2`.
//    - Reset `num1`, `num2` to zero after each comparison and increment pointers past the dot.
// 3. If all segments are equal, return `0`.

int compareVersion(string version1, string version2)
{
    int i = 0;
    int j = 0;
    int n1 = version1.size();
    int n2 = version2.size();
    int num1 = 0;
    int num2 = 0;
    while (i < n1 || j < n2)
    {
        while (i < n1 && version1[i] != '.')
        {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        while (j < n2 && version2[j] != '.')
        {
            num2 = num2 * 10 + (version2[j] - '0');
            ;
            j++;
        }
        if (num1 > num2)
            return 1;
        else if (num1 < num2)
            return -1;
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    return 0;
}
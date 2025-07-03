#include<iostream>
using namespace std;

// VALID NUMBER (LEETCODE 65)
// USING STRING PROCESSING - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize flags: `isdot` for '.', `nums` for digits, `ise` for 'e' or 'E'.
// 2. Traverse each character in the string:
//    - If it's a digit, set `nums = true`.
//    - If it's '+' or '-', it must be the first character or follow an 'e'/'E'.
//    - If it's 'e' or 'E':
//        - It must not be already seen and must follow a valid number.
//        - Set `ise = true` and reset `nums = false` to ensure digits follow 'e'.
//    - If it's '.', ensure no '.' or 'e' has been seen yet.
//    - If any other character is encountered, return false.
// 3. After loop, return true only if a number was parsed (ensures something follows 'e').

bool isNumber(string s)
{
    int n = s.size();
    bool isdot = false, nums = false, ise = false;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
            nums = true;
        else if (s[i] == '+' || s[i] == '-')
        {
            if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E'))
                return false;
        }
        else if (s[i] == 'e' || s[i] == 'E')
        {
            if (ise || !nums)
                return false;
            ise = true;
            nums = false;
        }
        else if (s[i] == '.')
        {
            if (isdot || ise)
                return false;
            isdot = true;
        }
        else
            return false;
    }
    return nums;
}
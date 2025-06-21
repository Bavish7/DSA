#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// CHECK PALINDROME WITH ALPHANUMERIC CHARACTERS
// USING TWO POINTERS - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize an empty string `ans` to store the filtered and normalized characters from the input string `s`.
// 2. Iterate through each character in `s`:
// a. If the character is a lowercase letter ('a' to 'z'), add it to `ans`.
// b. If the character is an uppercase letter ('A' to 'Z'), convert it to lowercase and add it to `ans`.
// c. If the character is a digit ('0' to '9'), add it to `ans`.
// 3. Initialize two pointers: `start` at the beginning of `ans` and `end` at the end of `ans`.
// 4. Compare characters at the `start` and `end` pointers:
// a. If they are not equal, return `false` as `ans` is not a palindrome.
// 5. Move the `start` pointer one step to the right and the `end` pointer one step to the left.
// 6. Continue comparing characters until `start` is greater than or equal to `end`.
// 7. If all characters match, return `true` as `ans` is a palindrome.

bool checkPalindrome(string s)
{
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += s[i] - 'A' + 'a';
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            ans += s[i];
        }
    }
    int start = 0;
    int end = ans.size() - 1;
    while (start < end)
    {
        if (ans[start] != ans[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}
int main(){
    string s;
    cin >> s;
    bool ans=checkPalindrome(s);
    cout << ans;
}

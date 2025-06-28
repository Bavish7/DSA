#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// REMOVE ALL OCCURRENCES OF A SUBSTRING
// USING FIND AND ERASE - TC=O(N*M), SC=O(1)

// Steps:
// 1. Start with a string `s` and a substring `part` that needs to be removed from `s`.
// 2. Use a `while` loop to repeatedly check if `part` exists in `s` and perform removal:
// a. Inside the loop, use the `find` method to locate the first occurrence of `part` in `s`.
// b. If `find` returns a position less than the length of `s`, it means `part` exists in `s`.
// c. Use the `erase` method to remove the substring `part` from `s` starting at the found position and spanning the length of `part`.
// 3. Continue the loop until `part` is no longer found in `s` (i.e., `find` returns a position equal to or greater than the length of `s`).
// 4. Return the modified string `s` after all occurrences of `part` have been removed.

string removeOccurrences(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main(){
    string s;
    cin >> s;
    string part;
    cin >> part;
    cout << removeOccurrences(s, part);
}
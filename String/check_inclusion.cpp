#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// CHECK INCLUSION
// USING SLIDING WINDOW - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize two arrays `count1` and `count2` of size 26 to zero. These will store the frequency of each character (a-z) for `s1` and the current window of `s2`, respectively.
// 2. Populate `count1` with the frequency of each character in `s1`.
// 3. Initialize `i` to 0 and `windowSize` to the length of `s1`.
// 4. Populate `count2` with the frequency of characters from the first window of `s2` (of size `windowSize`).
// 5. Compare `count1` and `count2` using the helper function `checkEqual`:
//    - If they are equal, return `true` as a permutation of `s1` is present in `s2`.
// 6. Slide the window across `s2`:
// a. For each new character added to the window, increment its count in `count2`.
// b. For each character removed from the window, decrement its count in `count2`.
// c. Compare `count1` and `count2` again using `checkEqual`:
//    - If they are equal at any point, return `true`.
// 7. If no permutation of `s1` is found in `s2`, return `false`.

bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};
    while (i < windowSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if (checkEqual(count1, count2))
    {
        return true;
    }
    while (i < s2.length())
    {
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;
        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;
        i++;
        if (checkEqual(count1, count2))
        {
            return true;
        }
    }
    return false;
}
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << checkInclusion(s1, s2);
}
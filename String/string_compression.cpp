#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// STRING COMPRESSION (LEETCODE 443)
// USING TWO POINTERS - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize `i` to traverse the input `chars` array and `ansIndex` to keep track of the position for writing compressed characters.
// 2. Iterate through the array using `i`:
// a. Set `j` to `i + 1` to find the end of the current sequence of identical characters.
// b. Increment `j` while the characters at `i` and `j` are the same and `j` is within bounds.
// c. Write the character at `i` to `chars[ansIndex]` and increment `ansIndex`.
// d. Compute the length of the current sequence (`count`) as `j - i`.
// e. If `count` is greater than 1, convert `count` to a string and write each digit to `chars[ansIndex]`.
// f. Update `i` to `j` to process the next sequence of characters.
// 3. Return `ansIndex` which represents the new length of the compressed `chars` array.

int compress(vector<char> &chars)
{
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();
    while (i < n)
    {
        int j = i + 1;
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }
        chars[ansIndex++] = chars[i];
        int count = j - i;
        if (count > 1)
        {
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}
int main()
{
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('a');
    chars.push_back('a');
    cout << compress(chars);
}
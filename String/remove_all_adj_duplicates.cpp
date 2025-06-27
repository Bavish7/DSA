#include<iostream>
using namespace std;

// REMOVE ALL ADJACENT DUPLICATES IN STRING II (LEETCODE 1209)
// USING STRING - TC=O(N*K), SC=O(1)

// Steps:
// 1. Iterate through the string 's' and build the result string 'ans'.
// 2. Check if the last k-1 characters in 'ans' are the same as the current character 'ch'.
// 3. If they are the same, remove the last k-1 characters from 'ans'.
// 4. If not, add the current character to 'ans'.
// 5. Return the final string 'ans' after processing the entire input string 's'.

bool areSame(string &ans, char &ch, int k_1)
{
    int it = ans.size() - 1;
    for (int i = 0; i < k_1; i++)
    {
        if (ch != ans[it])
        {
            return false;
        }
        it--;
    }
    return true;
}
string removeDuplicates(string s, int k)
{
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ans.size() < k - 1)
        {
            ans.push_back(ch);
        }
        else
        {
            if (areSame(ans, ch, k - 1))
            {
                for (int j = 0; j < k - 1; j++)
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans.push_back(ch);
            }
        }
    }
    return ans;
}

// USING TWO POINTERS APPROACH - TC=O(N), SC=O(N)

// Steps:
// 1. Use two pointers `i` and `j` to iterate through the string `s`.
// 2. Store the count of consecutive duplicate characters in the `count` vector.
// 3. If the count of duplicates equals `k`, move the `i` pointer back by `k` to remove those characters.
// 4. Continue the process until all characters in the string are checked.
// 5. Return the substring from `0` to `i`, which will be the resulting string after removing duplicates.

string removeDuplicates(string s, int k)
{
    int i = 0, j = 0;
    vector<int> count(s.size());
    while (j < s.size())
    {
        s[i] = s[j];
        count[i] = 1;
        if (i > 0 && s[i] == s[i - 1])
        {
            count[i] += count[i - 1];
        }
        if (count[i] == k)
        {
            i -= k;
        }
        i++;
        j++;
    }
    return s.substr(0, i);
}
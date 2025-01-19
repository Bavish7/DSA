#include<iostream>
using namespace std;

// LONGEST SUCCESSIVE ELEMENTS
// USING SORTING - TC=O(N*LOGN), SC=O(1)

// Steps:
// 1. Sort the array to bring consecutive elements next to each other.
// 2. Traverse the sorted array while skipping duplicates.
// 3. If the difference between consecutive elements is 1, increment the current sequence length (`ans`).
// 4. If a break in the sequence occurs, reset `ans` to 1.
// 5. Keep track of the maximum sequence length (`maxLen`) encountered so far.
// 6. Return `maxLen`.

int longestSuccessiveElements(vector<int> &a)
{
    sort(a.begin(), a.end());
    int ans = 1, maxLen = INT_MIN;
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i + 1] == a[i])
        {
            continue;
        }
        if (a[i + 1] - a[i] == 1)
        {
            ans++;
            maxLen = max(maxLen, ans);
        }
        else
        {
            ans = 1;
        }
    }
    return maxLen;
}

// USING UNORDERED SET - TC=O(N), SC=O(N)
// Steps:
// 1. Insert all elements of the array into an unordered set to allow O(1) lookups.
// 2. Iterate over the set to find the starting points of potential sequences (numbers that do not have a predecessor in the set).
// 3. For each starting point, extend the sequence by checking for consecutive numbers in the set.
// 4. Keep track of the maximum length of any sequence encountered (`maxLen`).
// 5. Return `maxLen`.

int longestSuccessiveElements(vector<int> &a)
{
    unordered_set<int> st;
    int n = a.size();
    int maxLen = 1;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x++;
                cnt++;
            }
            maxLen = max(maxLen, cnt);
        }
    }
    return maxLen;
}
#include<iostream>
using namespace std;

// SUPERIOR ELEMENTS
// USING FOR LOOP - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize an empty result vector `ans` to store superior elements.
// 2. Start from the rightmost element, set it as `maxi` (rightmost element is always superior).
// 3. Traverse the array from right to left:
//    - If the current element is greater than `maxi`, update `maxi` and add it to `ans`.
// 4. Sort the `ans` array in ascending order to match the desired output.
// 5. Return the sorted `ans` array.

vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int maxi = a[a.size() - 1];
    ans.push_back(maxi);
    for (int i = a.size() - 2; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            maxi = a[i];
            ans.push_back(maxi);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
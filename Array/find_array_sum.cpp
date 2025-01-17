#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// ADD 2 ARRAYS
// USING FOR LOOP - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize pointers for both arrays starting from the end and a carry variable.
// 2. Loop through both arrays, adding corresponding elements along with the carry.
// 3. If one array is exhausted, continue adding remaining elements from the other array with the carry.
// 4. If there's a remaining carry after processing both arrays, add it to the result.
// 5. Reverse the result to get the correct order and return it.

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }
    vector<int> ans = findArraySum(a, n, b, m);
    for (int i : ans)
    {
        cout << i << " ";
    }
}

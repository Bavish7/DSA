#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// MAX LENGTH OF SUBARRAY
// USING FOR LOOP - TC=O(N), SC=O(1)

// Steps:
// 1. Read the number of elements 'n' from the user.
// 2. Read 'n' elements into the array 'arr'.
// 3. Initialize variables 'pd' to store the previous difference and 'ans' to store the maximum length found so far.
// 4. Initialize 'curr' to store the current length of consecutive elements.
// 5. Loop through the array starting from the third element.
// 6. Check if the current difference is equal to the previous difference.
// 7. If true, increment 'curr'; otherwise, update 'pd' and reset 'curr'.
// 8. Update 'ans' with the maximum of itself and 'curr'.
// 9. Print 'ans', which represents the maximum length of subarrays with consecutive elements.

int main()
{
    int n;
    cout << "enter no. of terms : ";
    cin >> n;
    int arr[n];
    cout << "enter values : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int pd = arr[1] - arr[0];
    int ans = 2, curr = 2;
    for (int j = 2; j < n - 1; j++)
    {
        if (pd == arr[j] - arr[j - 1])
        {
            curr++;
        }
        else
        {
            pd = arr[j] - arr[j - 1];
            curr = 2;
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
 }
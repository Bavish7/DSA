#include <iostream>
#include <queue>
using namespace std;

// FIRST NEGATIVE INTEGER IN EVERY WINDOW OF SIZE K
// USING FIXED SIZE SLIDING WINDOW - TC=O(N), SC=O(K)

// Steps:
// 1. Initialize a deque `d` to keep track of indices of negative numbers in the current window.
// 2. Initialize a vector `ans` to store the result for each window.
// 3. For the first window of size `k` (from index 0 to k-1):
//    - If a negative number is found, add its index to the deque `d`.
// 4. If the deque is not empty after processing the first window, add the value of the first negative number (at the front of the deque) to `ans`.
//    Otherwise, add 0 to `ans` (indicating no negative number was found in this window).
// 5. For the remaining windows:
// - Check if the index at the front of the deque is out of the current window's range. If it is, remove it from the deque.
// - Add the index of the new negative number (if any) to the deque.
// - Add the value of the first negative number in the current window to `ans` if the deque is not empty. Otherwise, add 0.

vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{

    deque<int> d;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            d.push_back(i);
        }
    }
    if (d.size() > 0)
    {
        ans.push_back(arr[d.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    for (int i = k; i < n; i++)
    {
        if (!d.empty() && i - d.front() >= k)
        {
            d.pop_front();
        }
        if (arr[i] < 0)
        {
            d.push_back(i);
        }
        if (d.size() > 0)
        {
            ans.push_back(arr[d.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
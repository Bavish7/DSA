#include<iostream>
using namespace std;

// FIND K CLOSEST ELEMENTS (LEETCODE 658)
// USING TWO POINTERS APPROACH - TC=O(N-K), SC=O(K)

// Steps:
// 1. Initialize two pointers, `a` at the start and `b` at the end of the array.
// 2. Shrink the window between `a` and `b` until its size is equal to `k`.
// 3. At each step, compare the distance between `x` and the elements at `a` and `b`.
// 4. Move the pointer that points to the element farther from `x` to reduce the window size.
// 5. Once the window size is `k`, collect the elements within the window into the result vector.
// 6. Return the result vector containing the `k` closest elements.

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int n = arr.size();
    int a = 0;
    int b = n - 1;
    while (b - a >= k)
    {
        if (x - arr[a] <= arr[b] - x)
        {
            b--;
        }
        else
        {
            a++;
        }
    }
    vector<int> ans;
    for (int i = a; i <= b; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}

// USING BINARY SEARCH AND TWO POINTERS APPROACH - TC=O(LOGN+K), SC=O(K)

// Steps:
// 1. Implement `lowerBound` function to find the first element not less than `x` using binary search.
// 2. Initialize two pointers `l` and `h` around the position found by `lowerBound`.
// 3. Use a loop to adjust `l` and `h` to include the `k` closest elements to `x`.
// 4. In each iteration, compare distances from `x` and move the pointer that points to the element farther from `x`.
// 5. Once `k` elements are included, return the subarray from `l + 1` to `h`.

int lowerBound(vector<int> &arr, int x)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = end;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int h = lowerBound(arr, x);
    int l = h - 1;
    while (k--)
    {
        if (l < 0)
        {
            h++;
        }
        else if (h >= arr.size())
        {
            l--;
        }
        else if (x - arr[l] > arr[h] - x)
        {
            h++;
        }
        else
        {
            l--;
        }
    }
    return vector<int>(arr.begin() + l + 1, arr.begin() + h);
}
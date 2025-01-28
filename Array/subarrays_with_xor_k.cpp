#include<iostream>
using namespace std;

// SUBARRAYS WITH XOR K
// USING UNORDERED MAP AND PREFIX XOR - TC=O(N), SC=O(N)

// Steps:
// 1. Use a hash map (mp) to store the frequency of XOR values encountered so far.
// 2. Initialize `xr` (current XOR) to 0 and increment its frequency in the map.
// 3. Traverse the array while updating the current XOR (`xr`) with each element.
// 4. Compute `rem` as the XOR of the current XOR (`xr`) and the target value (`b`).
// 5. Check if `rem` exists in the map. If it does, add its frequency to the count, as these subarrays contribute to the target XOR.
// 6. Update the frequency of the current XOR (`xr`) in the map.
// 7. Return the total count of subarrays having XOR equal to `b`.

int subarraysWithSumK(vector<int> a, int b)
{
    unordered_map<int, int> mp;
    int xr = 0;
    mp[xr]++;
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        xr = xr ^ a[i];
        int rem = xr ^ b;
        count += mp[rem];
        mp[xr]++;
    }
    return count;
}
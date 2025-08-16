#include<iostream>
using namespace std;

// COUNT TRIPLETS THAT CAN FORM TWO ARRAYS OF EQUAL XOR (LEETCODE 1442)
// USING PREFIX XOR - TC=O(N^2), SC=O(N)

// Steps:
// 1. Build prefixXor such that prefixXor[i] = arr[0] ^ arr[1] ^ ... ^ arr[i-1].
//    (Extra 0 inserted at beginning for easy range XOR calculation).
// 2. Property: For indices i, j, k → if prefixXor[i] == prefixXor[k],
//    then arr[i] ^ ... ^ arr[j] == arr[j+1] ^ ... ^ arr[k-1].
//    → This means we found valid triplets (i, j, k).
// 3. For each (i, k) pair where prefixXor[i] == prefixXor[k],
//    the number of valid j indices between them is (k - i - 1).
// 4. Accumulate triplets count and return result.

int countTriplets(vector<int> &arr)
{
    vector<int> prefixXor(arr.begin(), arr.end());
    prefixXor.insert(prefixXor.begin(), 0);
    int n = prefixXor.size();
    for (int i = 1; i < n; i++)
    {
        prefixXor[i] ^= prefixXor[i - 1];
    }
    int triplets = 0;
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (prefixXor[i] == prefixXor[k])
            {
                triplets += (k - i - 1);
            }
        }
    }
    return triplets;
}
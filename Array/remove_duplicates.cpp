#include<iostream>
using namespace std;

// REMOVE DUPLICATES FROM SORTED ARRAY (LEETCODE 26)
// USING TWO POINTERS APPROACH - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize three pointers: 'prev' to track the position of the last unique element, 'curr' to iterate through the array, and 'k' to count the number of unique elements.
// 2. Iterate through the array with 'curr' starting from the second element.
// 3. If the current element is equal to the previous element, move 'curr' forward to skip duplicates.
// 4. If the current element is different from the previous element, update 'prev' to the next position, copy the current element to this new position in the array, and increment 'k'.
// 5. Return 'k + 1' which represents the new length of the array after removing duplicates.

int removeDuplicates(vector<int> &nums)
{
    int k = 0;
    int prev = 0;
    int curr = 1;
    int n = nums.size();
    while (curr < n)
    {
        if (nums[prev] == nums[curr])
        {
            curr++;
        }
        else
        {
            prev++;
            nums[prev] = nums[curr];
            k++;
        }
    }
    return k + 1;
}

// REMOVE DUPLICATES FROM SORTED ARRAY II (LEETCODE 80)
// USING TWO POINTERS APPROACH - TC=O(N), SC=O(1)

// Steps:
// 1. If array size is ≤ 2, return size directly (no excess duplicates).
// 2. Use a pointer `k` to track the position to insert the next valid element.
// 3. From index 2 onward, check if `nums[i] != nums[k-2]`:
//    - If so, it's not a 3rd+ duplicate → keep it: assign to `nums[k]` and increment `k`.
//    - Else, skip (it's an extra duplicate).
// 4. Return `k` as the new length with at most 2 duplicates per element.

int removeDuplicates(vector<int>& nums) {
    int n=nums.size();
    if(n<=2) return n;
    int k=2;
    for(int i=2;i<n;i++){
        if(nums[i]!=nums[k-2]){
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}
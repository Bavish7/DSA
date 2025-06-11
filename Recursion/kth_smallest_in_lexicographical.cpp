#include<iostream>
using namespace std;

// KTH SMALLEST IN LEXICOGRAPHICAL ORDER (LEETCODE 440)
// USING RECURSION - TC=O(LOGN^2), SC=O(1)

// Steps:
// 1. Simulate the lexicographical order traversal of numbers from 1 to n.
// 2. Start with `curr = 1`. Decrease k by 1, since we start from the first number.
// 3. At each step, compute how many numbers exist under the prefix `curr` (using countNum):
//    - Traverse the "tree" rooted at `curr`, multiplying by 10 at each level to expand deeper.
//    - At each level, add `next - curr` to the count (bounded by n).
// 4. If the count is less than or equal to k, move horizontally (curr++) and subtract count from k.
// 5. If the count is larger than k, move vertically (curr *= 10) and subtract 1 from k (counting the prefix itself).
// 6. Repeat until k == 0. The current number will be the k-th number.

int countNum(long curr, long next, int n){
    int count=0;
    while(curr<=n){
        count+=(next-curr);
        curr*=10;
        next*=10;
        next=min(next,(long)n+1);
    }
    return count;
}
int findKthNumber(int n, int k) {
    int curr=1;
    k--;
    while(k>0){
        int count=countNum(curr,curr+1,n);
        if(count<=k){
            curr++;
            k-=count;
        }
        else{
            curr*=10;
            k--;
        }
    }
    return curr;
}
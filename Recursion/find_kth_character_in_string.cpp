#include<iostream>
using namespace std;

// FIND KTH CHARACTER IN STRING GAME II (LEETCODE 3307)
// USING RECURSION - TC=O(LOGK), SC=O(LOGK)

// Steps:
// 1. Base Case: If k == 1, return 'a' (the first character in the string).
// 2. Each operation doubles the length of the current string by appending a modified version.
// 3. Find at which operation the total length first exceeds or equals k.
// 4. Recurse on the half where k lies, adjusting k relative to the previous string.
// 5. If operation is 1, apply transformation (next character), else keep character same.

char kthCharacter(long long k, vector<int>& operations) {
    if(k==1) return 'a';
    long long len=1;
    long long newK=-1;
    int operation=-1;
    for(int i=0;i<operations.size();i++){
        len*=2;
        if(len>=k){
            newK=k-len/2;
            operation=operations[i];
            break;
        }
    }
    char ch = kthCharacter(newK,operations);
    if(operation){
        if(ch=='z') return 'a';
        return ch+1;
    }
    else return ch;
}
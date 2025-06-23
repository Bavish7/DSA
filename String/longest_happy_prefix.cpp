#include<iostream>
using namespace std;

// LONGEST HAPPY PREFIX (LEETCODE 1392)
// USING KMP ALGORITHM. TC=O(N), SC=O(N)

// Steps:
// 1. Build the LPS (Longest Prefix Suffix) array for the input string.
//    - Initialize `len` as the current length of the longest prefix which is also suffix.
//    - Traverse the string starting from index 1:
//       - If characters match, increment `len`, set `lps[i] = len`, and move to next index.
//       - If not, and `len` is not 0, update `len = lps[len-1]` (try shorter prefix).
//       - If `len` is 0, set `lps[i] = 0` and move to next index.
// 2. The last value in the LPS array gives the length of the longest prefix which is also a suffix.
// 3. Return the substring from index 0 to that length.

vector<int>findLPS(string &s){
    int n=s.size();
    vector<int>lps(n,0);
    int i=1, len=0;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
string longestPrefix(string s) {
    vector<int>lps=findLPS(s);
    return s.substr(0,lps.back());
}
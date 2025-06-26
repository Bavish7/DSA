#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// MAXIMUM FREQUENCY OF A CHARACTER
// USING SORTING AND LINEAR SEARCH - TC=O(N*LOGN), SC=O(1)

// Steps:
// 1. Initialize a string `s1` with the input value. In this case, it is "abcaacbade".
// 2. Sort the string `s1` to group identical characters together. Sorting ensures that all occurrences of each character are contiguous.
// 3. Initialize two variables:
// a. `freq` to keep track of the current frequency of the character being counted. Set it to 1 since the character is counted once when it is first encountered.
// b. `maxf` to store the maximum frequency found. Initialize it to 0.
// 4. Iterate through the sorted string from the beginning to the end:
// a. If the current character is the same as the next character (`s1[i] == s1[i+1]`), increment the `freq` counter and update `maxf` with the maximum value between `maxf` and `freq`.
// b. If the current character is different from the next character, reset `freq` to 1, as the new character starts its count.
// 5. After the loop ends, `maxf` will contain the maximum frequency of any character in the string.
// 6. Print the result.

int main(){
    string s1="abcaacbade";
    sort(s1.begin(),s1.end());
    int freq=1;
    int maxf=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s1[i+1]){
            freq++;
            maxf=max(maxf,freq);
        }
        else{freq=0;}
    }cout<<maxf<<endl;
}
int main() {
    int n;
    cin>>n;
    string s="abcdefghijklmnopqrstuvwxyz";
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<a[i].length();j++){
            int l=1;
            l+=s.find(a[i][j]);
            if(l>3){
                l=l%3;
                if(l==0){
                l+=3;
                }
                count+=l;
            }
            else{
            count+=l;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
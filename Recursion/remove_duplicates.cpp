#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// REMOVE DUPLICATES FROM STRING

// Steps:
// 1. If the string is empty, return an empty string.
// 2. - Get the first character of the string.
//    - Recursively remove duplicates from the rest of the string.
//    - Check if the first character is the same as the first character of the result from the recursive call.
//    - If they are the same, return the result of the recursive call (skipping the duplicate).
//    - If they are different, prepend the first character to the result of the recursive call.

string remove(string s){
    if(s.length()==0){
        return"";
    }
    char ch=s[0];
    string ans=remove(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
        return ch+ans;
}
int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    cout<<remove(s);
}
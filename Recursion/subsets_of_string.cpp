#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// SUBSETS OF A STRING
// USING RECURSION - TC=O(2^N), SC=O(N * 2^N)

// Steps of the logic:
// 1. **Recursive Function (`subset`)**:
//    - **Base Case**: If the input string `s` is empty:
//      - Print the current subset `ans` (this is a subset of the original string).
//      - Return to explore other subsets.
//    - **Recursive Case**:
//      - **Exclude the Current Character**:
//        - Call `subset` recursively with the remaining substring and the current subset `ans` unchanged.
//      - **Include the Current Character**:
//        - Call `subset` recursively with the remaining substring and the current subset `ans` concatenated with the current character `ch`.
//
// 2. **Function Invocation**:
//    - Start the recursive function with the original string `s` and an empty `ans` string.

void subset(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string rest=s.substr(1);
    subset(rest,ans);
    subset(rest,ans+ch);
}
int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    subset(s,"");
}
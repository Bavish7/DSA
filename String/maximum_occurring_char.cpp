#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// MAXIMUM OCCURRING CHARACTER
// USING FREQUENCY ARRAY - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize a string `s1` with the input value, read from standard input.
// 2. Create an integer array `freq` of size 26 to store the frequency of each character. Each index represents a character ('a' to 'z') where `freq[0]` corresponds to 'a', `freq[1]` to 'b', and so on.
// 3. Iterate through each character of the string `s1`:
// a. Convert the character to an index (`s1[i] - 'a'`) and increment the corresponding value in the `freq` array to count the frequency of the character.
// 4. Initialize two variables:
// a. `ans` to store the character with the maximum frequency. Initialize it to 'a'.
// b. `max` to store the maximum frequency found. Initialize it to 0.
// 5. Iterate through the `freq` array from index 0 to 25:
// a. If the frequency of the character at index `i` (`freq[i]`) is greater than `max`, update `max` and set `ans` to the character corresponding to index `i` (`i + 'a'`).
// 6. Print the result, showing the character with the maximum frequency and the number of times it is repeated.

int main(){
    string s1;
    cin>>s1;
    int freq[26]={0};
    for(int i=0;i<s1.size();i++){
        freq[s1[i]-'a']++;
    }
    char ans='a';
    int max=0;
    for(int i=0;i<26;i++){
        if(freq[i]>max){
            max=freq[i];
            ans=i+'a';
        }
    }
    cout<<ans<<" is repeated "<<max<<" times";
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// MOVE ALL X AT END
string move(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans=move(s.substr(1));
    if(ch=='x'){
        return ans+ch;
    }
    return ch+ans;
}
int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    cout<<move(s);
}
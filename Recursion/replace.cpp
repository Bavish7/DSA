#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// REPLACE PI WITH 3.14
void replace(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replace(s.substr(2));
    }
    else{
        cout<<s[0];
        replace(s.substr(1));
    }
}
int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    replace(s);
}
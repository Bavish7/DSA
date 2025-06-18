#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s = "bavish";
    stack<char> st;
    for (int i = 0; i < s.length();i++){
        char ch = s[i];
        st.push(ch);
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}

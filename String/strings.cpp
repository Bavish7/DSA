#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    string s1="famii";
    string s2="ily";
    s1.append(s2);
    cout<<s1<<endl;
    cout<<s1.compare(s2)<<endl;
    s2.clear();
    if(s2.empty()){
        cout<<"empty"<<endl;
    }
    s1.erase(3,2);
    cout<<s1<<endl;
    cout<<s1.find("am")<<endl;
    s1.insert(3,"i");
    cout<<s1<<endl;
    cout<<s1.size()<<endl;
    s2=s1.substr(4,3);
    cout<<s2<<endl;
    string s3="198";
    int x= stoi(s3);
    cout<<x+1<<endl;
    cout<<to_string(x)+"9"<<endl;
    sort(s1.begin(),s1.end());
    cout<<s1<<endl;
    transform(s1.begin(),s1.end(),s1.begin(),::toupper);
    cout<<s1<<endl;
    sort(s3.begin(),s3.end(),greater<int>());
    cout<<s3<<endl;
}
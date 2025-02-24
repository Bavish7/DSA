#include <iostream>
using namespace std;

// COUNT NO. OF ONES IN NUMBER
int NoOfOnes(int n){
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}
int main(){
    cout<<NoOfOnes(18)<<endl;
}
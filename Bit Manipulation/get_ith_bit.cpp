#include<iostream>
using namespace std;

// CHECK ITH BIT OF A NUMBER
void getIthBit(int n, int i){
    int bitMask = 1 << i;
    int ans = n & bitMask;
    if(ans==0){
        cout << "Bit is 0";
    }
    else{
        cout << "Bit is 1";
    }
}

// SET ITH BIT OF A NUMBER
void setIthBit(int n, int i){
    int bitMask = 1 << i;
    n = n | bitMask;
    cout << "Updated number is: " << n;
}

// CLEAR ITH BIT OF A NUMBER
void clearIthBit(int n, int i){
    int bitMask = ~(1 << i);
    int ans = n & bitMask;
    cout << "Updated number is: " << ans;
}
int main(){
    int n;
    cin >> n;
    int i;
    cin >> i;
    // getIthBit(n, i);
    // setIthBit(n, i);
    clearIthBit(n, i);
}
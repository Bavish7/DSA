#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// POWER OF A NUMBER
// USING RECURSION - TC=O(LOGN), SC=O(LOGN)

// Steps:
// 1. If the exponent 'b' is 0, return 1 (base case).
// 2. If the exponent 'b' is 1, return 'a' (base case).
// 3. Recursively calculate power of 'a' to 'b/2' and store it in 'ans'.
// 4. If 'b' is even, return 'ans * ans' (since (a^(b/2))^2 = a^b).
// 5. If 'b' is odd, return 'a * ans * ans' (since a * (a^(b/2))^2 = a^b).

int power(int a, int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans = power(a, b / 2);
    if(b%2==0){
        return ans * ans;
    }
    else{
        return a * ans * ans;
    }
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << power(a, b);
}
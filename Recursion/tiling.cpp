#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TILING PROBLEM
int tiling(int n){
   if(n<=2){
      return n;
   }
   return tiling(n-1)+tiling(n-2);
}
int main(){
   int n;
   cout<<"Enter size of tiles : ";
   cin>>n;
   cout<<tiling(n);
}
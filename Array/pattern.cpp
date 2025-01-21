#include<iostream>
using namespace std;
// PATTERN 1
// int main()
// {   int rows;
//     cin>>rows;
//     int col;
//     cin>>col;
//     for(int i=1;i<=rows;i++)
//     {
//         for(int j=1;j<=col;j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// PATTERN 2
// int main()
// {
//     int row,col;
//     cin>>row>>col;
//     for(int i=1;i<=row;i++)
//     {
//         for(int j=1;j<=col;j++)
//         {
//             if((i==1 || i==row) ||( j==1 || j==col))
//             {
//                 cout<<"*";

//             }
//             else
//             {
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// PATTERN 3
// int main()
// {
//     int row,col;
//     cin>>row>>col;
//     for(int i=1;i<=row;i++)
//     {
//         for(int j=i;j<=col;j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// PATTERN 4
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(j<=n-i)
//             {
//                 cout<<" ";
//             }
//             else{
//                 cout<<"*";
//             }
//         }
//         cout<<endl;
//     }
// }

//PATTTERN 5
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=i;j++)
//         {
//             cout<<i;
//         }
//         cout<<endl;
//     }
//     return 0;
// }

//PATTERN 6 NUMBER
// int main(){
//     int r,c;
//     cout<<"enter no. of rows : ";
//     cin>>r;
//     for(int i=r;i>0;i--){
//         for(int j=1;j<=i;j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

//PATTERN 7 NUMBER
// int main(){
//     int r;
//     cout<<"enter rows : ";
//     cin>>r;
//     for(int i=1;i<=r;i++){
//         for(int j=1;j<=i;j++){
//             if((i+j)%2==0){
//                 cout<<"1";
//             }
//             else{
//                 cout<<"0";
//             }
//         }
//         cout<<endl;
//     }
// }

//RHOMBUS PATTERN
// int main(){
//     int r;
//     cout<<"enter rows : ";
//     cin>>r;
//     for(int i=1;i<=r;i++){
//         for(int j=1;j<=r-i;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=r;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

//PATTERN 9 NUMBER
// int main(){
//     int n;
//     cout<<"enter n : ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=n-1;j>=i;j--){
//             cout<<" ";
//         }
//         for(int k=1;k<=i;k++){
//             cout<<k<<" ";
//         }
//         cout<<endl;
//     }
// }

//PALINDROMIC PATTERN
// int main(){
//     int n;
//     cout<<"enter n : ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=n-1;j>=i;j--){
//             cout<<" ";
//         }
//         for(int k=i;k>=1;k--){
//             cout<<k;
//         }
//         for(int l=2;l<=i;l++){
//             cout<<l;
//         }
//         cout<<endl;
//     }
// }

//STAR PATTERN
int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=n-1;j>=i;j--){
            cout<<" ";
        }
        for(int k=i;k>=1;k--){
            cout<<"*";
        }
        for(int l=2;l<=i;l++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int a=1;a<=n;a++){
        for(int b=1;b<=a;b++){
            cout<<" ";
        }
        for(int k=n;k>a;k--){
            cout<<"*";
        }
        for(int l=n;l>a+1;l--){
            cout<<"*";
        }
        cout<<endl;
    }
}

//ZIG ZAG PATTERN
// int main(){
//     int n;
//     cout<<"enter n : ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=(n*n);j++){
//             if((i+j)%4==0 || (i==2 &&(j%4==0))){
//                 cout<<"* ";
//             }
//             else{
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
// }
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// int main(){
//     int n;
//     vector<int> v;  //zero length vector
//     vector<int> v2(3,50);   //prints 50 50 50
//     cout<<"Enter size of vector : ";
//     cin>>n;
//     int element;
//     cout<<"Enter elements : ";
//     for(int i=0;i<n;i++){
//         cin>>element;
//         v.push_back(element);
//     }
//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
//     vector<int> :: iterator it;
//     for(it=v.begin();it<v.end();it++){
//         cout<<*it<<" ";
//     }
//     cout<<endl;
//     for(auto element :v){
//         cout<<element<<" ";
//     }
//     v.pop_back();
//     swap(v,v2);
//     for(auto element :v){
//         cout<<element<<" ";
//     }
//     cout<<endl;
//     for(auto element :v2){
//         cout<<element<<" ";
//     }
//     cout<<endl;
//     sort(v2.begin(),v2.end());
//     for(auto element :v2){
//         cout<<element<<" ";
//     }
//     cout<<endl;
//     int m;
//     cout<<"Enter no. of rows : ";
//     cin>>n;
//     cout<<"Enter no. of columns : ";
//     cin>>m;
//     vector<vector<int>> grid(n,vector<int>(m,-1));
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             cout << grid[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

//PAIR
//Reduce the given matrix i.e. the min element's index with value 0. 
// bool compare(pair<int,int> p1, pair<int,int> p2){
//     return p1.first<p2.first;   //first denotes element in array
// }
// int main(){
//     int arr[]={10,16,7,14,5,3,12,9};
//     vector<pair<int,int>> v;
//     for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
//         v.push_back(make_pair(arr[i],i));
//     }
//     sort(v.begin(),v.end(),compare);
//     for(int i=0;i<v.size();i++){
//         arr[v[i].second]=i;
//     }
//     for(int i=0;i<v.size();i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
    
// }

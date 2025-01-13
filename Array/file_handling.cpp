#include<iostream>
#include<fstream>
using namespace std;

//CREATING/OPENING A FILE
// int main(){
//     fstream st;
//     st.open("C:\\files\\dst.txt",ios::out);
//     if(!st){
//         cout<<"file creation failed";
//     }
//     else{
//         cout<<"file created";
//         st.close();
//     }
// }

// WRITING
// int main(){
//     char data[100];
//     fstream st;
//     st.open("C:\\files\\dst.txt",ios::out);
//     if(!st){
//         cout<<"file creation failed";
//     }
//     else{
//         cout<<"file created"<<endl;
//         st<<"hello";
//         cout<<"Enter your name : ";
//         cin.getline(data,100);
//         st<<data<<endl;
//         st.close();
//     }
// }

//READING
// int main(){
//     fstream st;
//     st.open("C:\\files\\dst.txt",ios::in);
//     if(!st){
//         cout<<"file creation failed";
//     }
//     else{
//         char ch[100];
//         while(!st.eof()){
//             st.getline(ch,100);
//             cout<<ch;
//         }
//         st.close();
//     }
//     return 0;
// }

int main(){
    char data[100];
    fstream infile("C:\\files\\dst.txt", ios::in);
    fstream outfile("C:\\files\\ast.txt",ios::out);
    if (infile && outfile)
    {
        while(infile>>data){
            for(int i=0;i<100;i+=2){
            infile>>data[i];
            outfile<<data[i];
            }
        }
        cout<<"Copy finished";
    }
    else{
        cout<<"Cannot read file";

    }
    infile.close();
    outfile.close();    
}

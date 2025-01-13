#include<iostream>
using namespace std;

//CONSTRUCTORS
// class student{
//     public:
//     string name;
//     int age;
//     int marks;
//     student(string n, int a, int m){ //PARAMETERISED CONSTRUCTOR
//         name=n;
//         age=a;
//         marks=m;
//     }
//     student(student &a){ //COPY CONSTRUCTOR
//         name=a.name;
//         age=a.age;
//         marks=a.marks;
//     }
//     ~student(){
//         cout<<"destructor called";
//     }
//     void get(){
//         cout<<"name is : "<<name<<endl;
//         cout<<"age is : "<<age<<endl;
//         cout<<"marks are : "<<marks<<endl;
//     }
// };
// int main(){
//     student a("Bavish",19,90);
//     student c=a; 
//     a.get();
// }

//SINGLE INHERITANCE
// class a{
//     public:
//         void func(){
//             cout<<"inherited";
//         }
// };
// class b: public a{
// };
// int main(){
//     b b1;
//     b1.func();
// }

//MULTIPLE INHERITANCE
// class a{
//     public:
//         void funca(){
//             cout<<"function a\n";
//         }
// };
// class b{
//     public:
//         void funcb(){
//             cout<<"function b\n";
//         }
// };
// class c: public a,public b{
//     public:
// };
// int main(){
//     c c1;
//     c1.funca();
//     c1.funcb();
// }

//MULTILEVEL INHERITANCE
// class a{
//     public:
//         void funca(){
//             cout<<"function a\n";
//         }
// };
// class b: public a{
//     public:
//         void funcb(){
//             cout<<"function b\n";
//         }
// };
// class c: public b{
//     public: 
// };
// int main(){
//     c c1;
//     c1.funca();
//     c1.funcb();
// }

//FUNCTION OVERLOADING 
// class a{
//     public:
//         void fun(){
//             cout<<"function with no arguments\n";
//         }
//         void fun(int a){
//             cout<<"function with one argument\n";
//         }
//         void fun(double a, double b){
//             cout<<"function with two arguments\n";
//         }
// };
// int main(){
//     a a1;
//     a1.fun();
//     a1.fun(3);
//     a1.fun(3.5,5);
// }

//OPERATOR OVERLOADING
// class complex{
//     int real,img;
//     public:
//     complex(int r,int i){
//         real=r;
//         img=i;
//     }
//     complex(){
//     }
//     complex operator + (complex const &obj){
//         complex res;
//         res.img=img +obj.img;
//         res.real=real +obj.real;
//         return res;
//     }
//     void display(){
//         cout<<real<<" + "<<img<<"i"<<endl;
//     }
// };
// int main(){
//     complex c1(12,7), c2(6,7);
//     complex c3=c1+c2;
//     c3.display();
// }

//VIRTUAL FUNCTIONS
// class base{
//     public:
//     virtual void print(){
//         cout<<"this is base class print"<<endl;
//     }
//     void display(){
//         cout<<"this is base class display"<<endl;
//     }
// };
// class derived : public base{
//     public :
//     void print(){
//         cout<<"this is derived class print"<<endl;
//     }
//     void display(){
//         cout<<"this is derived class display"<<endl;
//     }
// };
// int main(){
//     base *b;
//     derived d;
//     b=&d;
//     b -> print();
//     b -> display();
// }




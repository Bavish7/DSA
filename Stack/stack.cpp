#include<iostream>
#include<stack>
using namespace std;

// INFIX TO POSTFIX
// int prec(char c){
//     if(c=='^'){
//         return 3;
//     }
//     else if(c=='/' || c=='*'){
//         return 2;
//     }
//     else if(c=='+' || c=='-'){
//         return 1;
//     }
//     else
//         return -1;
// }
// void infixToPostfix(string s){
//     stack<char> st;
//     string result;
//     for (int i = 0; i < s.length();i++){
//         char c = s[i];
//         if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
//             result += c;
//         }
//         else if(c=='('){
//             st.push(c);
//         }
//         else if(c==')'){
//             while(st.top()!='('){
//                 result += st.top();
//                 st.pop();
//             }
//             st.pop();
//         }
//         else{
//             while(!st.empty() && prec(c)<= prec(st.top())){
//                 result += st.top();
//                 st.pop();
//             }
//             st.push(c);
//         }
//     }
//     while(!st.empty()){
//         result += st.top();
//         st.pop();
//     }
//     cout << result << endl;
// }
// int main()
// {
//     string s;
//     cout << "Enter string: ";
//     cin >> s;
//     infixToPostfix(s);
// }

// INFIX TO POSTFIX
// int prec(char c){
//     if(c=='^'){
//         return 3;
//     }
//     else if(c=='/' || c=='*'){
//         return 2;
//     }
//     else if(c=='+' || c=='-'){
//         return 1;
//     }
//     else
//         return -1;
// }
// void infixToPostfix(string s){
//     stack<char> st;
//     string result;
//     for (int i = 0; i < s.length();i++){
//         char c = s[i];
//         if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
//             st.push(c);
//         }
//         else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
//             while(!st.empty()){
//                 char a = st.top();
//                 st.pop();
//                 char b = st.top();
//                 st.pop();
//                 result += '('+b+c+a+')';
//                 cout << result;
//             }
//         }
//     }
//     cout << result << endl;
// }
// int main()
// {
//     string s;
//     cout << "Enter string: ";
//     cin >> s;
//     infixToPostfix(s);
// }

#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *stackArray;

public:
    Stack(int stackSize)
    {
        size = stackSize;
        top = -1;
        stackArray = new int[size];
    }
    ~Stack()
    {
        delete[] stackArray;
    }
    bool isFull()
    {
        return top == size - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full!" << endl;
        }
        else
        {
            stackArray[++top] = value;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Popped value: " << stackArray[top--] << endl;
        }
    }
    void display()
    {
        cout << "Stack Elements: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << stackArray[i] << " ";
        }
        cout << endl;
    }
    void average()
    {
        float sum = 0;
        for (int i = 0; i <= top; ++i)
        {
            sum += stackArray[i];
        }
        cout << "Average of the stack values is: "<<sum/size;
    }
};

int main()
{
    Stack myStack(6);
    myStack.push(0);
    myStack.push(1);
    myStack.push(5);
    myStack.push(2);
    myStack.push(4);
    myStack.push(7);
    myStack.display();
    myStack.average();
    return 0;
}

#include<iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;
    Stack(int size){
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }
    void push(int data){
        if(top==size-1){
            cout << "Stack overflow" << endl;
            return;
        }
        else{
            top++;
            arr[top] = data;
        }
    }
    void pop(){
        if(top==-1){
            cout << "Stack underflow" << endl;
            return;
        }
        else{
            top--;
        }
    }
    int getTop(){
        if(top==-1){
            return -1;
        }
        else{
            return arr[top];
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    int getSize(){
        return top + 1;
    }
};
int main(){
    Stack st(3);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.getTop();
}
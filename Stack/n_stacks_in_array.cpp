#include<iostream>
using namespace std;

// Steps:
// 1. Initialize `n` stacks using arrays `a`, `top`, and `next`, along with `freespot` to manage free space.
// 2. Constructor initializes arrays and links free slots in `next`.
// 3. `push(x, m)` inserts element `x` into stack `m`:
//    - Check if there's a free slot using `freespot`.
//    - Use `freespot` to find the next available slot and update the arrays accordingly.
//    - Update `top` to reflect the new top of stack `m`.
// 4. `pop(m)` removes the top element from stack `m`:
//    - Check if stack `m` is empty using `top`.
//    - Use `top[m-1]` to get the top index and adjust `freespot` and `next` for free management.
//    - Return the popped element.

class NStack
{
public:
    int *a, *top, *next, freespot, n, s;
    NStack(int N, int S)
    {
        this->n = N;
        this->s = S;
        freespot = 0;
        a = new int[s];
        top = new int[n];
        next = new int[s];
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < s - 1; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
    }
    bool push(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }
        int index = freespot;
        freespot = next[index];
        a[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
        return true;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        int element = a[index];
        next[index] = freespot;
        freespot = index;
        return element;
    }
};
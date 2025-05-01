#include<iostream>
using namespace std;

// LONGEST HAPPY STRING (LEETCODE 1405)
// CREATE MAXHEAP TO PUSH ALL CHARACTERS WITH THEIR FREQUENCY. TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Define a class `Info` to store characters and their counts.
// 2. Define a comparator class to sort `Info` objects based on their counts in descending order for the max heap.
// 3. Initialize a max heap (priority queue) and push `Info` objects for 'a', 'b', and 'c' into it if their counts are greater than 0.
// 4. Construct the result string by repeatedly taking the two most frequent characters from the heap:
//    - Append the most frequent character up to 2 times (depending on its count).
//    - Append the second most frequent character up to 2 times (depending on its count and ensuring it does not exceed the remaining count of the first character).
//    - Push the characters back into the heap if they still have remaining counts.
// 5. Handle the case where only one character is left in the heap.
// 6. Return the constructed result string.

class Info
{
public:
    char value;
    int count;
    Info(char value, int count)
    {
        this->value = value;
        this->count = count;
    }
};
class compare
{
public:
    bool operator()(Info *first, Info *second)
    {
        return first->count < second->count;
    }
};
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<Info *, vector<Info *>, compare> maxHeap;
        if (a > 0)
        {
            Info *temp = new Info('a', a);
            maxHeap.push(temp);
        }
        if (b > 0)
        {
            Info *temp = new Info('b', b);
            maxHeap.push(temp);
        }
        if (c > 0)
        {
            Info *temp = new Info('c', c);
            maxHeap.push(temp);
        }
        string ans = "";
        while (maxHeap.size() > 1)
        {
            Info *first = maxHeap.top();
            maxHeap.pop();
            Info *second = maxHeap.top();
            maxHeap.pop();
            if (first->count >= 2)
            {
                ans.push_back(first->value);
                ans.push_back(first->value);
                first->count -= 2;
            }
            else
            {
                ans.push_back(first->value);
                first->count--;
            }
            if (second->count >= 2 && second->count >= first->count)
            {
                ans.push_back(second->value);
                ans.push_back(second->value);
                second->count -= 2;
            }
            else
            {
                ans.push_back(second->value);
                second->count--;
            }
            if (first->count > 0)
            {
                maxHeap.push(first);
            }
            if (second->count > 0)
            {
                maxHeap.push(second);
            }
        }
        if (maxHeap.size() == 1)
        {
            Info *first = maxHeap.top();
            maxHeap.pop();
            if (first->count >= 2)
            {
                ans.push_back(first->value);
                ans.push_back(first->value);
                first->count -= 2;
            }
            else
            {
                ans.push_back(first->value);
                first->count--;
            }
        }
        return ans;
    }
};
#include<iostream>
using namespace std;

// REORGANIZE STRING(LEETCODE 767)
// CREATE MAXHEAP TO PUSH ALL CHARACTERS WITH THEIR FREQUENCY. TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Calculate the frequency of each character in the input string.
// 2. Use a max-heap to store characters based on their frequencies.
//    - For each character with non-zero frequency, create an Info object and push it into the heap.
// 3. Reorganize the string by repeatedly taking the two most frequent characters from the heap:
//    - Add these characters to the result string and decrement their frequencies.
//    - If any character still has a remaining count, push it back into the heap.
// 4. If there is one character left in the heap after processing all others, add it to the result string.
//    - If this character's count is more than one, return an empty string since reorganization is not possible.
// 5. Return the reorganized string.

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
    string reorganizeString(string s)
    {
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            freq[c - 'a']++;
        }
        priority_queue<Info *, vector<Info *>, compare> maxHeap;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                Info *temp = new Info(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }
        string ans = "";
        while (maxHeap.size() > 1)
        {
            Info *first = maxHeap.top();
            maxHeap.pop();
            Info *second = maxHeap.top();
            maxHeap.pop();
            ans.push_back(first->value);
            first->count--;
            ans.push_back(second->value);
            second->count--;
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
            Info *last = maxHeap.top();
            maxHeap.pop();
            ans.push_back(last->value);
            last->count--;
            if (last->count > 0)
            {
                return "";
            }
        }
        return ans;
    }
};
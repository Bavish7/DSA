#include<iostream>
using namespace std;

// TOP K FREQUENT WORDS (LEETCODE 692)
// USING UNORDERED MAP AND MIN HEAP - TC=O(N*LOGK), SC=O(N)

// Steps:
// 1. Create a custom comparator class (Compare) to sort by frequency in decreasing order and by lexicographical order when frequencies are the same.
// 2. In the topKFrequent function, first count the frequency of each word using an unordered_map.
// 3. Create a min-heap (priority_queue) with pairs of frequency and word, using the custom comparator to maintain the top k frequent words.
// 4. Traverse the frequency map, and for each word, push it into the heap.
//    - If the heap size exceeds k, pop the smallest element (since we only need the top k frequent words).
// 5. After processing all words, extract words from the heap (the most frequent word will be at the root), and insert them at the beginning of the result vector.
// 6. Return the result vector containing the top k frequent words.

class Solution
{
    class Compare
    {
    public:
        bool operator()(const pair<int, string> &a, const pair<int, string> &b)
        {
            if (a.first == b.first)
                return a.second < b.second;
            else
                return a.first > b.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> count;
        for (auto word : words)
            count[word]++;
        vector<string> result;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for (auto it : count)
        {
            pq.push({it.second, it.first});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            result.insert(result.begin(), pq.top().second);
            pq.pop();
        }
        return result;
    }
};
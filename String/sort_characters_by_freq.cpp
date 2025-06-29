#include<iostream>
using namespace std;

// SORT CHARACTERS BY FREQUENCY (LEETCODE 451)
// USING HASHMAP AND PRIORITY QUEUE - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Create a hashmap to store the frequency of each character in the input string `s`.
// 2. Create a max heap to sort characters based on their frequency.
//    - The heap will store pairs of characters and their frequencies.
// 3. Traverse the hashmap and push each pair to the heap.
// 4. Build the sorted string by popping characters from the heap and appending them to the result.
// 5. Return the sorted string.

string frequencySort(string s)
{
    unordered_map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }
    priority_queue<pair<int, char>> pq;
    for (auto it : freq)
    {
        pq.push({it.second, it.first});
    }
    string ans = "";
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        ans += string(p.first, p.second);
    }
    return ans;
}

// USING HASHMAP AND BUCKET SORT - TC=O(N), SC=O(N)
// Steps:
// 1. Create a hashmap to store the frequency of each character in the input string `s`.
// 2. Create a bucket to store characters based on their frequency.
//    - The bucket will store strings of characters at each frequency index.
// 3. Traverse the hashmap and add each character to the corresponding frequency index in the bucket.
// 4. Build the sorted string by iterating over the bucket from the end and appending characters to the result.
// 5. Return the sorted string.

string frequencySort(string s)
{
    unordered_map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }
    vector<string> bucket(s.size() + 1, "");
    for (auto it : freq)
    {
        bucket[it.second] += it.first;
    }
    string ans = "";
    for (int i = s.size(); i > 0; i--)
    {
        for (char c : bucket[i])
        {
            ans += string(i, c);
        }
    }
    return ans;
}


#include<iostream>
using namespace std;

// WORD LADDER (LEETCODE 127)
// USING BFS TRAVERSAL - TC=O(N*L), SC=O(N)

// Steps:
// 1. Use an unordered set `st` to store all words from `wordList` for quick lookup. Remove `beginWord` from `st`.
// 2. Initialize a queue with `beginWord` and a starting transformation length of 1.
// 3. While the queue is not empty:
//    a. Get the current word and its length.
//    b. If the current word is `endWord`, return the length as the shortest transformation sequence.
//    c. For each character in the current word, try replacing it with every letter from 'a' to 'z'.
//       i. If the modified word is in `st`, remove it from `st` to avoid revisiting and add it to the queue with length+1.
// 4. If no transformation sequence reaches `endWord`, return 0.

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);
    q.push({beginWord, 1});
    while (!q.empty())
    {
        string word = q.front().first;
        int len = q.front().second;
        q.pop();
        if (word == endWord)
        {
            return len;
        }
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (int ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, len + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

// WORD LADDER II (LEETCODE 126)
// USING BFS AND DFS TRAVERSAL - TC=O(N*L), SC=O(N*L)

// Steps:
// 1. BFS Phase:
//    a. Use BFS to populate the `mp` map with the minimum steps needed to reach each word from `beginWord`.
//    b. For each word, explore possible transformations by changing one letter at a time.
//    c. If a valid transformation is found in the set, push it to the queue, remove from the set, and set its steps in `mp`.
// 2. DFS Phase:
//    a. Use DFS and `mp` to backtrack from `endWord` to `beginWord`, constructing all shortest paths.
//    b. For each word, modify one letter at a time, checking if it is one step shorter in `mp`.
//    c. If a valid transformation is found, add to `seq`, recurse, and then backtrack by removing from `seq`.
// 3. Return the result list of all shortest transformation sequences.

string b;
vector<vector<string>> ans;
unordered_map<string, int> mp;
void dfs(string word, vector<string> &seq)
{
    if (word == b)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }
    for (int i = 0; i < word.size(); i++)
    {
        char original = word[i];
        int len = mp[word];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if (mp.find(word) != mp.end() && mp[word] + 1 == len)
            {
                seq.push_back(word);
                dfs(word, seq);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    queue<string> q;
    b = beginWord;
    unordered_set<string> st(wordList.begin(), wordList.end());
    q.push({beginWord});
    mp[beginWord] = 1;
    st.erase(beginWord);
    while (!q.empty())
    {
        string word = q.front();
        int len = mp[word];
        q.pop();
        if (word == endWord)
            break;
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.count(word))
                {
                    q.push(word);
                    st.erase(word);
                    mp[word] = len + 1;
                }
            }
            word[i] = original;
        }
    }
    if (mp.find(endWord) != mp.end())
    {
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq);
    }
    return ans;
}
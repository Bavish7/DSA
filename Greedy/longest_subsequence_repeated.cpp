#include<iostream>
using namespace std;

// LONGEST SUBSEQUENCE REPEATED K TIMES (LEETCODE 2014)
// USING BFS AND GREEDY ALGORITHM - TC=O(26^(N/K)*N), SC=O(26^(N/K))

// Steps:
// 1. Count frequency of each character in the input string s.
// 2. Build a list of candidate characters (those that appear at least k times) in reverse lexicographical order.
// 3. Use BFS to explore combinations of these candidates starting from length 1 strings.
// 4. For each string in the queue, simulate whether it can form a subsequence repeated k times in s using isPresent().
// 5. If valid, extend it by adding each candidate character and push the new string to the queue.
// 6. Always update the result with the lexicographically larger or longer valid subsequence.
// 7. Return the longest valid repeated subsequence found.

bool isPresent(string sub, string s, int k){
    int n=s.size(), count=0, i=0;
    for(char &ch: s){
        if(ch==sub[i]){
            i++;
            if(i==sub.size()){
                i=0;
                count++;
                if(count==k) return true;
            }
        }
    }
    return false;
}
string longestSubsequenceRepeatedK(string s, int k) {
    vector<int>mp(26,0);
    int n=s.size();
    for(int i=0;i<n;i++){
        mp[s[i]-'a']++;
    }
    vector<char>candidates;
    for(int i=25;i>=0;i--){
        if(mp[i]>=k){
            candidates.push_back(i+'a');
        }
    }
    queue<string>q;
    for(char &ch: candidates){
        q.push(string(1,ch));
    }
    string ans="";
    while(!q.empty()){
        string curr=q.front();
        q.pop();
        if(curr.size()>ans.size()){
            ans=curr;
        }
        for(char &ch: candidates){
            string next=curr+ch;
            if(isPresent(next,s,k)){
                q.push(next);
            }
        }
    }
    return ans;
}
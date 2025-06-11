#include<iostream>
using namespace std;

// SUBSTRING WITH CONCATENATION OF ALL WORDS (LEETCODE 30)
// USING SLIDING WINDOW - TC=O(N*M), SC=O(M)

// Steps:
// 1. Count the frequency of each word in the input list `words` using a hash map.
// 2. Let each word be of length `len` and total number of words be `wordsize`.
// 3. Traverse `s` starting at each offset `i` in range [0, len) to cover all alignment possibilities.
// 4. For each alignment, slide a window of total size `len * wordsize` over `s`.
//    - At each step, extract a substring of size `len`.
//    - If it is in `counts`, increment its frequency in the sliding window map.
//    - If a word appears too many times, shrink the window from the left to adjust frequency and maintain valid state.
//    - If the count of matched words equals `wordsize`, record the starting index.
// 5. If a word is not in the original list, reset the window and continue from the next position.

vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string,int> counts;
    for (int i = 0; i < words.size(); i++){
        counts[words[i]]++;
    }
    int n = s.length();
    int wordsize = words.size();
    int len = words[0].size();
    vector<int> ans;
    for (int i = 0; i < len; i++) {
        int start = i, count = 0;
        unordered_map<string, int> mp;
        for (int j = i; j <= n - len; j += len) {
            string word = s.substr(j, len);
            if (counts.find(word) != counts.end()) {
                mp[word]++;
                count++;
                while (mp[word] > counts[word]) {
                    string leftword = s.substr(start, len);
                    mp[leftword]--;
                    count--;
                    start += len;
                }
                if (count == wordsize)
                    ans.push_back(start);
            } else {
                mp.clear();
                count = 0;
                start = j + len;
            }
        }
    }
    return ans;
}
#include<iostream>
using namespace std;

// DESIGN TWITTER (LEETCODE 355)
// USING MIN HEAP - TC=O(N*LOGK), SC=O(N)

// Steps:
// 1. Use an unordered_map to store followers and followees. 
// 2. Use another unordered_map to store tweets with timestamps. 
// 3. Implement postTweet() to append tweets to the user's list. 
// 4. Use getNewsFeed() to fetch the 10 most recent tweets from the user and their followees using a min-heap. 
// 5. Implement follow() and unfollow() to update the follower list. 
// 6. Maintain a priority queue to efficiently track recent tweets. 
// 7. Ensure efficient retrieval by iterating over relevant tweets and storing them in a heap of size 10. 
// 8. Optimize operations using hash sets and vectors for quick access and insertion.

struct Compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
class Twitter
{
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timestamp;
    Twitter()
    {
        timestamp = 0;
    }
    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({tweetId, timestamp});
        timestamp++;
    }
    vector<int> getNewsFeed(int userId)
    {
        unordered_set<int> followers = following[userId];
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto const &user : followers)
        {
            for (auto const &tweet : tweets[user])
            {
                pq.push(tweet);
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        for (auto &tweet : tweets[userId])
        {
            pq.push(tweet);
            if (pq.size() > 10)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};
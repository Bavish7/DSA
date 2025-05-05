#include<iostream>
using namespace std;

// TASK SCHEUDLER (LEETCODE 621)
// USING MAX HEAP - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Count the frequency of each task using a frequency array `mp`.  
// 2. Push all non-zero frequencies into a max heap (`pq`) to always process the most frequent task first.  
// 3. Initialize `time = 0` to track the total time required.  
// 4. In each cycle of `n + 1` intervals:  
//    a. Process up to `n + 1` tasks, reducing their frequency.  
//    b. Store remaining tasks (if their frequency is still > 0) in a temporary list.  
//    c. Increase `time` for each processed task.  
// 5. Reinsert remaining tasks back into the heap.  
// 6. If the heap is empty, break the loop; otherwise, add the remaining cycle time to `time`.  
// 7. Return the total time required.  

int leastInterval(vector<char> &tasks, int n)
{
    priority_queue<int> pq;
    vector<int> mp(26, 0);
    for (char i : tasks)
    {
        mp[i - 'A']++;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (mp[i])
            pq.push(mp[i]);
    }
    int time = 0;
    while (!pq.empty())
    {
        vector<int> remain;
        int cycle = n + 1;
        while (cycle and !pq.empty())
        {
            int max_freq = pq.top();
            pq.pop();
            if (max_freq > 1)
            {
                remain.push_back(max_freq - 1);
            }
            ++time;
            --cycle;
        }
        for (int count : remain)
        {
            pq.push(count);
        }
        if (pq.empty())
            break;
        time += cycle;
    }
    return time;
}

// USING FORMULA - TC=O(N), SC=O(1)
// Steps:
// 1. Count the frequency of each task using a frequency array `mp`.  
// 2. Determine the maximum frequency `max_freq` among all tasks.  
// 3. Count how many tasks have this maximum frequency (`count_maxfreq`).  
// 4. Compute the minimum time required using the formula:  
//    - `(max_freq - 1) * (n + 1) + count_maxfreq`  
//    - This accounts for full cycles of `n + 1` slots, plus additional slots for the most frequent tasks.  
// 5. Return the maximum of this computed time and the total number of tasks (`sz`) to handle cases where idle time is unnecessary.  

int leastInterval(vector<char> &tasks, int n)
{
    vector<int> mp(26, 0);
    int max_freq = 0, count_maxfreq = 0, sz = tasks.size();
    for (char i : tasks)
    {
        mp[i - 'A']++;
        if (mp[i - 'A'] > max_freq)
        {
            max_freq = mp[i - 'A'];
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (mp[i] == max_freq)
            count_maxfreq++;
    }
    int time = (max_freq - 1) * (n + 1) + count_maxfreq;
    return max(time, sz);
}
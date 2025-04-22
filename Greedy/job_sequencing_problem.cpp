#include<iostream>
using namespace std;

// JOB SEQUENCING PROBLEM
// USING GREEDY APPROACH - TC=O(N * MAX DEADLINE), SC=O(MAX DEADLINE)

// Steps:
// 1. Sort the jobs in descending order based on their profit.
// 2. Find the maximum deadline among all the jobs to determine the size of the schedule array.
// 3. Initialize the schedule array with -1 to mark all time slots as free.
// 4. Iterate through each job and try to schedule it:
//    - Start from the job's deadline and move backwards to find a free slot.
//    - If a free slot is found, schedule the job, increment the job count, and add its profit to the total profit.
// 5. Return a vector containing the total number of jobs done and the total profit.

static bool cmp(vector<int> a, vector<int> b)
{
    return a[2] > b[2];
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);
    int maxDeadline = INT_MIN;
    int n = jobs.size();
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][1]);
    }
    vector<int> schedule(maxDeadline + 1, -1);
    int count = 0;
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int currID = jobs[i][0];
        int currDead = jobs[i][1];
        int currProfit = jobs[i][2];
        for (int k = currDead; k > 0; k--)
        {
            if (schedule[k] == -1)
            {
                count++;
                maxProfit += currProfit;
                schedule[k] = currID;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxProfit);
    return ans;
}

// USING SET - TC=O(N * LOG MAX(N, MAX DEADLINE)), SC=O(MAX DEADLINE)
// Steps:
// 1. Sort the jobs in descending order based on their profit.
// 2. Find the maximum deadline among all the jobs to determine the range of available slots.
// 3. Initialize a set of available slots from the maximum deadline to 1 (inclusive).
// 4. Iterate through each job and try to schedule it:
//    - Use lower_bound to find the latest available slot on or before the job's deadline.
//    - If a valid slot is found, schedule the job, increment the job count, and add its profit to the total profit.
//    - Remove the used slot from the set to mark it as occupied.
// 5. Return a vector containing the total number of jobs done and the total profit.

#include <algorithm>
#include <set>

bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[2] > job2[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), compare);
    int maxProfit = 0;
    int numberOfJobs = 0;
    int maxDeadline = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][1]);
    }
    set<int, greater<int>> slots;
    for (int i = maxDeadline; i > 0; i--)
    {
        slots.insert(i);
    }
    vector<int> ans;
    for (int i = 0; i < jobs.size(); i++)
    {
        if (slots.size() == 0 || jobs[i][1] < *slots.rbegin())
        {
            continue;
        }
        int availableSlot = *slots.lower_bound(jobs[i][1]);
        maxProfit = maxProfit + jobs[i][2];
        numberOfJobs += 1;
        slots.erase(availableSlot);
    }
    ans.push_back(numberOfJobs);
    ans.push_back(maxProfit);
    return ans;
}
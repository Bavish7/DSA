#include<iostream>
using namespace std;

// MAXIMUM NUMBER OF TASKS YOU CAN ASSIGN (LEETCODE 2071)
// USING BINARY SEARCH AND DEQUE - TC=O(NLOGN+MLOGM+(N+M)*LOG(MIN(N,M))), SC=O(M)

// Steps:
// 1. Sort both `tasks` and `workers` in ascending order.
// 2. Apply Binary Search on the answer: maximum number of tasks that can be assigned.
//    → Range is [0, min(tasks.size(), workers.size())]
// 3. For each mid value, call `canAssign()` to check if `mid` tasks can be assigned.
//    a. Try to assign the hardest tasks (from the `taskCount-1` down to 0) using:
//       - A strong enough worker (>= task)
//       - A weaker worker who can do it with a pill (worker + strength >= task)
//       - Use deque to manage workers that require pills.
//    b. If pills run out or no valid workers left, return false.
// 4. Update binary search bounds based on `canAssign()` result.

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int low = 0, high = min(tasks.size(), workers.size());
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (canAssign(tasks, workers, pills, strength, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
bool canAssign(const vector<int>& tasks, const vector<int>& workers, int pills, int strength, int taskCount) {
    deque<int> boosted;
    int w = workers.size() - 1;
    int freePills = pills;
    for (int t = taskCount - 1; t >= 0; --t) {
        int task = tasks[t];
        if (!boosted.empty() && boosted.front() >= task) {
            boosted.pop_front();
        } else if (w >= 0 && workers[w] >= task) {
            --w;
        } else {
            while (w >= 0 && workers[w] + strength >= task) {
                boosted.push_back(workers[w--]);
            }
            if (boosted.empty() || freePills == 0) {
                return false;
            }
            boosted.pop_back();
            --freePills;
        }
    }
    return true;
}
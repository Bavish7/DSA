#include<iostream>
using namespace std;

// MEETING ROOMS III (LEETCODE 2402)
// USING GREEDY ALGORITHM - TC=O(M*N), SC=O(N)

// Steps:
// 1. Sort the meetings by their start time to process them in chronological order
// 2. Initialize `lastTime` array to track when each room is free (initially all 0)
// 3. Initialize `countMeetings` array to track number of meetings handled by each room
// 4. For each meeting:
//    a. Try to assign it to the first room which becomes free before or at its start time
//    b. If such a room is found:
//       - Update that room’s free time to current meeting’s end
//       - Increment that room’s meeting count
//    c. Else (no room is available):
//       - Find the room with the earliest free time (greedy choice)
//       - Delay the meeting to start when that room is free and update its end accordingly
//       - Increment that room’s meeting count
// 5. After all meetings, find the room with the highest number of meetings
//    - If tie, return the smallest room index

int mostBooked(int n, vector<vector<int>>& meetings) {
    int m=meetings.size();
    sort(meetings.begin(),meetings.end());
    vector<long long>lastTime(n,0);
    vector<int>countMeetings(n,0);
    for(int i=0;i<meetings.size();i++){
        int start=meetings[i][0];
        int end=meetings[i][1];
        long long earlyEnd=LLONG_MAX;
        int earlyRoom=0;
        bool found=false;
        for(int room=0;room<n;room++){
            if(lastTime[room]<=start){
                lastTime[room]=end;
                countMeetings[room]++;
                found=true;
                break;
            }
            if(lastTime[room]<earlyEnd){
                earlyEnd=lastTime[room];
                earlyRoom=room;
            }
        }
        if(!found){
            lastTime[earlyRoom]+=(end-start);
            countMeetings[earlyRoom]++;
        }
    }
    int maxMeetings=0;
    int room=0;
    for(int i=0;i<n;i++){
        if(countMeetings[i]>maxMeetings){
            maxMeetings=countMeetings[i];
            room=i;
        }
    }
    return room;
}

// USING MIN HEAP - TC=O(M*LOGN), SC=O(N)
// Steps:
// 1. Sort all meetings based on start time.
// 2. Use two min-heaps:
//    - availableRooms: stores available room numbers (sorted smallest first)
//    - usedRooms: stores {endTime, room} for currently used rooms
// 3. For each meeting:
//    a. Release rooms from usedRooms if their endTime <= meeting's start
//    b. If availableRooms is not empty, assign meeting to the smallest room
//    c. Else, delay meeting to the endTime of earliest finishing room
// 4. For each assigned meeting, increment countMeetings[room]
// 5. After processing all meetings, find the room with max meetings
//    - If tie, choose the room with the smallest index

int mostBooked(int n, vector<vector<int>>& meetings) {
    int m=meetings.size();
    sort(meetings.begin(),meetings.end());
    vector<int>countMeetings(n,0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>usedRooms;
    priority_queue<int, vector<int>, greater<int>>availableRooms;
    for(int i=0;i<n;i++){
        availableRooms.push(i);
    }
    for(int i=0;i<m;i++){
        int start=meetings[i][0];
        int end=meetings[i][1];
        while(!usedRooms.empty() && usedRooms.top().first<=start){
            int room=usedRooms.top().second;
            usedRooms.pop();
            availableRooms.push(room);
        }
        if(!availableRooms.empty()){
            int room=availableRooms.top();
            availableRooms.pop();
            usedRooms.push({end,room});
            countMeetings[room]++;
        }
        else{
            int room=usedRooms.top().second;
            long long endTime=usedRooms.top().first;
            usedRooms.pop();
            usedRooms.push({endTime+(end-start),room});
            countMeetings[room]++;
        }
    }
    int maxMeetings=0;
    int room=0;
    for(int i=0;i<n;i++){
        if(countMeetings[i]>maxMeetings){
            maxMeetings=countMeetings[i];
            room=i;
        }
    }
    return room;
}

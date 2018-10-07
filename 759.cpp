/*We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:
Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)

Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

Note:

schedule and schedule[i] are lists with lengths in range [1, 50].
0 <= schedule[i].start < schedule[i].end <= 10^8.*/



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct mycmp{
        bool operator()(pair<int,Interval> &p1,pair<int,Interval> &p2){
            return p1.second.start > p2.second.start;
        }
    };
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> result;
        vector<int> index(schedule.size(),1);
        priority_queue<pair<int,Interval>,vector<pair<int,Interval>>,mycmp> pq;
        for(int i = 0;i != schedule.size();++i)
            pq.push(make_pair(i,schedule[i][0]));
        int timestamp = pq.top().second.end;
        while(!pq.empty()){
            pair<int,Interval> top = pq.top();
            if(top.second.start > timestamp){
                Interval interval(timestamp,top.second.start);
                result.push_back(interval);
                timestamp = top.second.end;
            }
            else{
                timestamp = max(timestamp,top.second.end);
            }
            pq.pop();
            if(index[top.first] != schedule[top.first].size()){
                pq.push(make_pair(top.first,schedule[top.first][index[top.first]]));
                index[top.first]++;
            }
        }
        return result;
    }
};

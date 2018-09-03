/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1*/

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
        bool operator()(Interval &i1,Interval &i2){
            return i1.start <= i2.start;
        }
    }cmp;
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<Interval>> vec(1);
        vec[0].push_back(intervals[0]);
        for(int i = 1;i != intervals.size();++i){
            bool push = false;
            for(int j = 0;j != vec.size();++j){
                if(vec[j].back().end <= intervals[i].start){
                    vec[j].push_back(intervals[i]);
                    push = true;
                    break;
                }
            }
            if(!push){
                vector<Interval> v;
                v.push_back(intervals[i]);
                vec.push_back(v);
            }
        }
        return vec.size();
    }
};

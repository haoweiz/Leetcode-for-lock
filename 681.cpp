/*Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.*/


class Solution {
public:
    string totime(int time){
        int hours = time/60;
        int minute = time%60;
        string h = to_string(hours);
        string m = to_string(minute);
        string result = "";
        if(h.size() == 1)
            result = result + "0" + h;
        else
            result = result + h;
        if(m.size() == 1)
            result = result + "0" + m;
        else
            result = result + m;
        return result;
    }
    string nextClosestTime(string time) {
        int hours = atoi(time.substr(0,2).c_str());
        int minute = atoi(time.substr(3,2).c_str());
        int total = 60*hours+minute;
        int distance = 1;
        unordered_set<char> us;
        us.insert(time[0]);
        us.insert(time[1]);
        us.insert(time[3]);
        us.insert(time[4]);
        while(true){
            int end = total+distance;
            if(end >= 24*60){
                end = end-24*60;
            }
            string timeend = totime(end);
            bool flag = true;
            for(int i = 0;i != timeend.size();++i){
                if(us.find(timeend[i]) == us.end()){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return timeend.substr(0,2)+":"+timeend.substr(2,2);
            distance++;
        }
    }
};

class Solution {
public:
    string nextClosestTime(string time) {
        string result = time;
        set<char> s({time[0],time[1],time[3],time[4]});
        string str(s.begin(),s.end());
        for(int i = time.size()-1;i >= 0;--i){
            if(time[i] == ':') continue;
            int position = str.find(time[i]);
            if(position == str.size()-1){
                result[i] = str[0];
            }
            else{
                char next = str[position + 1];
                if (i == 4) {
                    result[i] = next;
                    return result;
                } 
                else if (i == 3 && next <= '5') {
                    result[i] = next;
                    return result; 
                } 
                else if (i == 1 && (result[0] != '2' || (result[0] == '2' && next <= '3'))) {
                    result[i] = next;
                    return result;
                } 
                else if (i == 0 && next <= '2') {
                    result[i] = next;
                    return result;
                }
                result[i] = str[0];
            }
        }
        return result;
    }
};


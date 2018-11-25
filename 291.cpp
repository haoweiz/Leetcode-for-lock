/*Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Example 1:

Input: pattern = "abab", str = "redblueredblue"
Output: true

Example 2:

Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
Output: true

Example 3:

Input: pattern = "aabb", str = "xyzabcxzyabc"
Output: false

Notes:
You may assume both pattern and str contains only lowercase letters.
*/

class Solution {
public:
    bool backtrace(int p1,int p2,string &pattern,string &str,unordered_map<char,string> &um,unordered_set<string> &us){
        if(p1 == pattern.size() && p2 == str.size()){
            return true;
        }
        if(um.find(pattern[p1]) != um.end()){
            string s = um[pattern[p1]];
            if(p2+s.size() > str.size() || str.substr(p2,s.size()) != s)
                return false;
            if(backtrace(p1+1,p2+s.size(),pattern,str,um,us))
                return true;
        }
        else{
            for(int i = p2;i != str.size();++i){
                string s = str.substr(p2,i-p2+1);
                um[pattern[p1]] = s;
                if(us.find(s) != us.end()){
                    um.erase(pattern[p1]);
                    continue;
                }
                us.insert(s);
                if(backtrace(p1+1,i+1,pattern,str,um,us))
                    return true;
                us.erase(s);
                um.erase(pattern[p1]);
            }
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char,string> um;
        unordered_set<string> us;
        return backtrace(0,0,pattern,str,um,us);
    }
};

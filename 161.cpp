/*Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(abs(m-n) >= 2) return false;
        if(abs(m-n) == 1){
            bool del = false;
            int p1 = 0;
            int p2 = 0;
            while(p1 != s.size() && p2 != t.size()){
                if(s[p1] != t[p2]){
                    if(del) return false;
                    del = true;
                    if(m > n) p1++;
                    else p2++;
                }
                else{
                    p1++;
                    p2++;
                }
            }
            return true;
        }
        else{
            bool replace = false;
            for(int i = 0;i != m;++i){
                if(s[i] != t[i]){
                    if(!replace)
                        replace = true;
                    else
                        return false;
                }
            }
            return replace;
        }
    }
};

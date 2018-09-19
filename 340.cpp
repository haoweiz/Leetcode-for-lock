/*Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int start = 0;
        int end = 0;
        int result = 0;
        unordered_map<char,int> count;
        while(end != s.size()){
            if(count.size() < k){
                count[s[end]]++;
                end++;
            }
            else{
                count[s[end]]++;
                while(count.size() != k){
                    count[s[start]]--;
                    if(count[s[start]] == 0)
                        count.erase(s[start]);
                    start++;
                }
                end++;
            }
            result = max(result,end-start);
        }
        return result;    
    }
};

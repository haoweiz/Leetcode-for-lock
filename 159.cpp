/*Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0;
        int end = 0;
        int result = 0;
        unordered_map<char,int> count;
        while(end != s.size()){
            if(count.size() <= 1){
                count[s[end]]++;
                end++;
            }
            else{
                count[s[end]]++;
                while(count.size() != 2){
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

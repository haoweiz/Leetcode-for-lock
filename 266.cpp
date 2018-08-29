/*Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true*/


class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.size() == 0)
            return 0;
        int odds = 0;
        vector<int> count(128,0);
        for(int i = 0;i != s.size();++i)
            count[s[i]]++;
        for(int i = 0;i != count.size();++i)
            if(count[i]%2 == 1)
                odds++;
        if(odds >= 2) return false;
        if(odds == 1 && s.size()%2 == 0) return false;
        return true;
    }
};

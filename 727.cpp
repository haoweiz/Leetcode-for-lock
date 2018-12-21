/*Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.

 

Note:

    All the strings in the input will only contain lowercase letters.
    The length of S will be in the range [1, 20000].
    The length of T will be in the range [1, 100].
*/

class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size();
        int n = T.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j = 0;j != m;++j){
            if(T[0] == S[j])
                dp[0][j] = j;
            else{
                if(j != 0)
                    dp[0][j] = dp[0][j-1];
            }
        }
        for(int i = 1;i != n;++i){
            for(int j = 0;j != m;++j){
                if(S[j] == T[i]){
                    if(T[i] == T[i-1]){
                        if(j != 0)
                            dp[i][j] = dp[i-1][j-1];
                    }
                    else
                        dp[i][j] = dp[i-1][j];
                }
                else{
                    if(j != 0)
                        dp[i][j] = dp[i][j-1];
                }
            }
        }
        string result = "";
        int minlength = INT_MAX;
        for(int j = 0;j != m;++j){
            if(dp[n-1][j] != -1 && j-dp[n-1][j]+1 < minlength){
                minlength = j-dp[n-1][j]+1;
                result = S.substr(dp[n-1][j],minlength);
            }
        }
        return result;
    }
};

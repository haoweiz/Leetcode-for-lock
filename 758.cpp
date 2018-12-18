/* Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Note:

    words has length in range [0, 50].
    words[i] has length in range [1, 10].
    S has length in range [0, 500].
    All characters in words[i] and S are lowercase letters.
*/

class Solution {
public:
    void setBold(vector<bool> &bold,int start,int end){
        for(int i = start;i <= end;++i)
            bold[i] = true;
    }
    string boldWords(vector<string>& words, string S) {
        vector<bool> bold(S.size(),false);
        for(int i = 0;i != words.size();++i){
            int last = S.size()-words[i].size();
            for(int j = 0;j <= last;++j){
                int pointer = j;
                int pword = 0;
                while(pword != words[i].size() && S[pointer] == words[i][pword]){
                    pointer++;
                    pword++;
                }
                if(pword == words[i].size())
                    setBold(bold,j,j+words[i].size()-1);
            }
        }
        string result = "";
        int pointer = 0;
        while(pointer != S.size()){
            if(!bold[pointer]){
                result += S[pointer];
                pointer++;
                continue;
            }
            result += "<b>";
            while(pointer != S.size() && bold[pointer]){
                result += S[pointer];
                pointer++;
            }
            result += "</b>";
        }
        return result;
    }
};

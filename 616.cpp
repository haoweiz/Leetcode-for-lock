/*Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

Example 1:

Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"

Example 2:

Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"

Note:

    The given dict won't contain duplicates, and its length won't exceed 100.
    All the strings in input have length in range [1, 1000].
*/

class Solution {
public:    
    void setBold(vector<bool> &bold,int start,int end){
        for(int i = start;i <= end;++i)
            bold[i] = true;
    }
    string addBoldTag(string S, vector<string>& words) {
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

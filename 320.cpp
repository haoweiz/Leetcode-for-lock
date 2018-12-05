/*Write a function to generate the generalized abbreviations of a word. 

Note: The order of the output does not matter.

Example:

Input: "word"
Output:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

class Solution {
public:
    void backtrace(string &word,int start,vector<string> &result){
        for (int i = start;i < word.size();++i) {
            for (int j = 1;i+j <= word.size();++j) {
                string str = word.substr(0,i);
                str += to_string(j) + word.substr(i+j);
                result.push_back(str);
                backtrace(str,i+1+to_string(j).size(),result);
            }
        }
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> result({word});
        backtrace(word,0,result);
        return result;
    }
};

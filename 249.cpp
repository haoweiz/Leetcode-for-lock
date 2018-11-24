/*Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> um;
        for(int i = 0;i != strings.size();++i){
            string key = "";
            for(int j = 1;j != strings[i].size();++j){
                if(strings[i][j] >= strings[i][j-1])
                    key += to_string(strings[i][j]-strings[i][j-1]);
                else
                    key += to_string(strings[i][j]+26-strings[i][j-1]);
            }
            um[key].push_back(strings[i]);
        }
        vector<vector<string>> result;
        for(auto iter:um)
            result.push_back(iter.second);
        return result;
    }
};

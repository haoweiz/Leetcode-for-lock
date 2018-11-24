/*Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]

Example 2:

Input: "abc"
Output: []

*/

class Solution {
public:
    void backtrace(unordered_map<char,int> &um,string path,unordered_set<string> &result,int count){
        if(count == 0){
            result.insert(path);
            return;
        }
        for(auto iter:um){
            if(iter.second != 0){
                if(iter.second%2 == 0){
                    um[iter.first] -= 2;
                    if(um[iter.first] == 0)
                        count--;
                    backtrace(um,iter.first+path+iter.first,result,count);
                    if(um[iter.first] == 0)
                        count++;
                    um[iter.first] += 2;
                }
                else{
                    um[iter.first]--;
                    if(um[iter.first] == 0)
                        count--;
                    int mid = path.size()/2;
                    string newpath = path.substr(0,mid)+iter.first+path.substr(mid,mid);
                    backtrace(um,newpath,result,count);
                    if(um[iter.first] == 0)
                        count++;
                    um[iter.first]++;
                }
            }
        }
    }
    vector<string> generatePalindromes(string s) {
        unordered_map<char,int> um;
        for(int i = 0;i != s.size();++i)
            um[s[i]]++;
        int odds = 0;
        for(auto iter:um){
            if(iter.second%2 == 1)
                odds++;
        }
        if(odds >= 2) {
            vector<string> result;
            return result;
        }
        int count = um.size();
        unordered_set<string> us;
        backtrace(um,"",us,count);
        vector<string> result(us.begin(),us.end());
        return result;
    }
};

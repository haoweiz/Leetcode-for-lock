/*Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int result = INT_MAX;
        int last1 = -1;
        int last2 = -1;
        for(int i = 0;i != words.size();++i){
            if(words[i].compare(word1) == 0){
                last1 = i;
                if(last2 != -1){
                    result = min(result,i-last2);
                }
            }
            if(words[i].compare(word2) == 0){
                last2 = i;
                if(last1 != -1){
                    result = min(result,i-last1);
                }
            }
        }
        return result;
    }
};

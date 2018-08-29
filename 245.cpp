/*Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int result = INT_MAX;
        int last = -1;
        for(int i = 0;i != words.size();++i){
            if(words[i].compare(word1) == 0 || words[i].compare(word2) == 0){
                if(last != -1 && (words[i] != words[last] || word1.compare(word2) == 0))
                    result = min(result,i-last);
                last = i;
            }
        }
        return result;
    }
};


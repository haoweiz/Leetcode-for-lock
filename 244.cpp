/*Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.*/


class WordDistance {
public:
    unordered_map<string,vector<int>> um;
    WordDistance(vector<string> words) {
        for(int i = 0;i != words.size();++i)
            um[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        vector<int> a = um[word1];
        vector<int> b = um[word2];
        int result = INT_MAX;
        int p1 = 0;
        int p2 = 0;
        while(p1 != a.size() || p2 != b.size()){
            if(p1 == a.size()){
                result = min(abs(a[p1-1]-b[p2]),result);
                p2++;
                continue;
            }
            if(p2 == b.size()){
                result = min(abs(a[p1]-b[p2-1]),result);
                p1++;
                continue;
            }
            if(a[p1] < b[p2]){
                result = min(b[p2]-a[p1],result);
                p1++;
            }
            else{
                result = min(a[p1]-b[p2],result);
                p2++;
            }
        }
        return result;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

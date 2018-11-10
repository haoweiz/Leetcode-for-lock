/*Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:
The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].*/

class Solution {
public:
    string Find(unordered_map<string,string> &parent,string target){
        if(parent[target] == target)
            return target;
        return Find(parent,parent[target]);
    }
    void Union(unordered_map<string,string> &parent,unordered_map<string,int> &rank,string p1,string p2){
        string pp1 = Find(parent,p1);
        string pp2 = Find(parent,p2);
        if(pp1 == pp2) return;
        if(rank[pp1] > rank[pp2]) parent[pp2] = pp1;
        else if(rank[pp1] < rank[pp2]) parent[pp1] = pp2;
        else{
            parent[pp2] = pp1;
            rank[pp1]++;
        }
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int m = words1.size();
        int n = words2.size();
        if(m != n) return false;
        unordered_map<string,string> parent;
        unordered_map<string,int> rank;
        for(int i = 0;i != pairs.size();++i){
            string p1 = pairs[i].first;
            string p2 = pairs[i].second;
            parent[p1] = p1;
            parent[p2] = p2;
            rank[p1] = 0;
            rank[p2] = 0;
        }
        for(int i = 0;i != pairs.size();++i){
            Union(parent,rank,pairs[i].first,pairs[i].second);
        }
        for(int i = 0;i != m;++i){
            if(Find(parent,words1[i]) != Find(parent,words2[i]))
                return false;
        }
        return true;
    }
};

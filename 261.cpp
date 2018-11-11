/*Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false

Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/


class Solution {
public:
    int Find(vector<int> &parent,int target){
        if(parent[target] == target)
            return target;
        return Find(parent,parent[target]);
    }
    bool Union(vector<int> &parent,vector<int> &rank,int x,int y){
        int px = Find(parent,x);
        int py = Find(parent,y);
        if(px == py) return false;
        if(rank[px] > rank[py]) parent[py] = px;
        else if(rank[px] < rank[py]) parent[px] = py;
        else{
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        for(int i = 0;i != n;++i)
            parent[i] = i;
        for(int i = 0;i != edges.size();++i){
            if(!Union(parent,rank,edges[i].first,edges[i].second))
                return false;
        }
        int root = Find(parent,0);
        for(int i = 1;i != n;++i){
            if(Find(parent,i) != root)
                return false;
        }
        return true;
    }
};

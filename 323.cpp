/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2

Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
public:
    int Find(vector<int> &parent,int target){
        if(target == parent[target])
            return target;
        return Find(parent,parent[target]);
    }
    void Union(vector<int> &parent,vector<int> &rank,int x,int y){
        int px = Find(parent,x);
        int py = Find(parent,y);
        if(px == py) return;
        if(rank[px] > rank[py]) parent[py] = px;
        else if(rank[px] < rank[py]) parent[px] = py;
        else{
            parent[py] = px;
            rank[px]++;
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        for(int i = 0;i != n;++i){
            parent[i] = i;
        }
        for(int i = 0;i != edges.size();++i){
            Union(parent,rank,edges[i].first,edges[i].second);
        }
        unordered_set<int> us;
        for(int i = 0;i != n;++i){
            us.insert(Find(parent,i));
        }
        return us.size();
    }
};

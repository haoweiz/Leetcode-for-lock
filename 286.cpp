/*You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

class Solution {
public:
    void dfs(int x,int y,int value,vector<vector<int>> &rooms){
        int m = rooms.size();
        int n = rooms[0].size();
        if(rooms[x][y] < value) return;
        rooms[x][y] = value;
        if(x-1 >= 0){
            dfs(x-1,y,value+1,rooms);
        }
        if(x+1 < m){
            dfs(x+1,y,value+1,rooms);
        }
        if(y-1 >= 0){
            dfs(x,y-1,value+1,rooms);
        }
        if(y+1 < n){
            dfs(x,y+1,value+1,rooms);
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if(m == 0) return;
        int n = rooms[0].size();
        if(n == 0) return;
        for(int i = 0;i != m;++i){
            for(int j = 0;j != n;++j){
                if(rooms[i][j] == 0){
                    dfs(i,j,0,rooms);
                }
            }
        }
    }
};

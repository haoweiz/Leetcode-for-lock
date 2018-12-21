/*Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:

11000
11000
00011
00011

Given the above grid map, return 1.

Example 2:

11011
10000
00001
11011

Given the above grid map, return 3.

Notice that:

11
1

and

 1
11

are considered different island shapes, because we do not consider reflection / rotation.

Note: The length of each dimension in the given grid does not exceed 50. */


class Solution {
public:
    void dfs(int x,int y,vector<vector<int>> &grid,vector<vector<bool>> &visited,string &str){
        visited[x][y] = true;
        if(x-1 >= 0 && grid[x-1][y] == 1 && !visited[x-1][y]){
            str += "U";
            dfs(x-1,y,grid,visited,str);
        }
        else
            str += "N";
        if(x+1 < grid.size() && grid[x+1][y] == 1 && !visited[x+1][y]){
            str += "D";
            dfs(x+1,y,grid,visited,str);
        }
        else
            str += "N";
        if(y-1 >= 0 && grid[x][y-1] == 1 && !visited[x][y-1]){
            str += "L";
            dfs(x,y-1,grid,visited,str);
        }
        else
            str += "N";
        if(y+1 < grid[0].size() && grid[x][y+1] == 1 && !visited[x][y+1]){
            str += "R";
            dfs(x,y+1,grid,visited,str);
        }
        else
            str += "N";
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        unordered_map<string,int> um;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0;i != m;++i){
            for(int j = 0;j != n;++j){
                if(grid[i][j] == 0 || visited[i][j]) continue;
                string str = "";
                dfs(i,j,grid,visited,str);
                um[str]++;
            }
        }
        return um.size();
    }
};

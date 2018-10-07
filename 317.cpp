/*You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7 

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total 
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.*/

class Solution {
public:
    struct node{
        int x,y;
        int distance;
        node(int xx,int yy,int dist):x(xx),y(yy),distance(dist){}
    };
    void helper(int x,int y,int dist,vector<vector<int>> &reachnumber,vector<vector<int>> &distance,vector<vector<bool>> &visited,queue<node*> &q,vector<vector<int>>& grid,int &count){
        if(x-1 >= 0 && !visited[x-1][y]){
            visited[x-1][y] = true;
            if(grid[x-1][y] == 0){
                distance[x-1][y] += (dist+1);
                q.push(new node(x-1,y,dist+1));
                reachnumber[x-1][y]++;
            }
            else if(grid[x-1][y] == 1){
                count++;
            }
        }
        if(y-1 >= 0 && !visited[x][y-1]){
            visited[x][y-1] = true;
            if(grid[x][y-1] == 0){
                distance[x][y-1] += (dist+1);
                q.push(new node(x,y-1,dist+1));
                reachnumber[x][y-1]++;
            }
            else if(grid[x][y-1] == 1){
                count++;
            }
        }
        if(x+1 < grid.size() && !visited[x+1][y]){
            visited[x+1][y] = true;
            if(grid[x+1][y] == 0){
                distance[x+1][y] += (dist+1);
                q.push(new node(x+1,y,dist+1));
                reachnumber[x+1][y]++;
            }
            else if(grid[x+1][y] == 1){
                count++;
            }
        }
        if(y+1 < grid[0].size() && !visited[x][y+1]){
            visited[x][y+1] = true;
            if(grid[x][y+1] == 0){
                distance[x][y+1] += (dist+1);
                q.push(new node(x,y+1,dist+1));
                reachnumber[x][y+1]++;
            }
            else if(grid[x][y+1] == 1){
                count++;
            }
        }
    }
    int shortestDistance(vector<vector<int>>& grid) {
        int result = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        int buildings = 0;
        vector<vector<int>> distance(m,vector<int>(n,0));
        vector<vector<int>> reachnumber(m,vector<int>(n,0));
        for(int i = 0;i != m;++i){
            for(int j = 0;j != n;++j){
                if(grid[i][j] == 2)
                    distance[i][j] = INT_MAX;
                else if(grid[i][j] == 1)
                    buildings++;
            }
        }
        for(int i = 0;i != m;++i){
            for(int j = 0;j != n;++j){
                if(grid[i][j] == 1){
                    vector<vector<bool>> visited(m,vector<bool>(n,false));
                    queue<node*> q;
                    int x = i,y = j;
                    int count = 1;
                    visited[i][j] = true;
                    if(x-1 >= 0 && !visited[x-1][y]){
                        if(grid[x-1][y] == 0){
                            visited[x-1][y] = true;
                            distance[x-1][y] += 1;
                            q.push(new node(x-1,y,1));
                            reachnumber[x-1][y]++;
                        }
                    }
                    if(y-1 >= 0 && !visited[x][y-1]){
                        if(grid[x][y-1] == 0){
                            visited[x][y-1] = true;
                            distance[x][y-1] += 1;
                            q.push(new node(x,y-1,1));
                            reachnumber[x][y-1]++;
                        }
                    }
                    if(x+1 < grid.size() && !visited[x+1][y]){
                        if(grid[x+1][y] == 0){
                            visited[x+1][y] = true;
                            distance[x+1][y] += 1;
                            q.push(new node(x+1,y,1));
                            reachnumber[x+1][y]++;
                        }
                    }
                    if(y+1 < grid[0].size() && !visited[x][y+1]){
                        if(grid[x][y+1] == 0){
                            visited[x][y+1] = true;
                            distance[x][y+1] += 1;
                            q.push(new node(x,y+1,1));
                            reachnumber[x][y+1]++;
                        }
                    }
                    while(!q.empty()){
                        node *front = q.front();
                        q.pop();
                        x = front->x;
                        y = front->y;
                        helper(x,y,front->distance,reachnumber,distance,visited,q,grid,count);
                    }
                }
            }
        }
        for(int i = 0;i != m;++i){
            for(int j = 0;j != n;++j){
                if(reachnumber[i][j] == buildings)
                    result = min(result,distance[i][j]);
            }
        }
        if(result == INT_MAX || result == 0) return -1;
        return result;
    }
};

/*There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

 

Example 1:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: 12

Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
             The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Example 2:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: -1

Explanation: There is no way for the ball to stop at the destination.

 

Note:

    There is only one ball and one destination in the maze.
    Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
    The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
    The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

*/


class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& maze,vector<vector<int>> &mindist,int path,vector<int>& destination){
        mindist[x][y] = path;
        int m = maze.size();
        int n = maze[0].size();
        
        int row = x;
        int col = y;
        while(row >= 1 && maze[row-1][col] == 0){
            row--;
        }
        if(path+x-row < mindist[row][col]){
            dfs(row,col,maze,mindist,path+x-row,destination);
        }
        
        row = x;
        col = y;
        while(row <= m-2 && maze[row+1][col] == 0){
            row++;
        }
        if(path+row-x < mindist[row][col]){
            dfs(row,col,maze,mindist,path+row-x,destination);
        }
        
        row = x;
        col = y;
        while(col >= 1 && maze[row][col-1] == 0){
            col--;
        }
        if(path+y-col < mindist[row][col]){
            dfs(row,col,maze,mindist,path+y-col,destination);
        }
        
        row = x;
        col = y;
        while(col <= n-2 && maze[row][col+1] == 0){
            col++;
        }
        if(path+col-y < mindist[row][col]){
            dfs(row,col,maze,mindist,path+col-y,destination);
        }
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        int x = start[0];
        int y = start[1];
        vector<vector<int>> mindist(m,vector<int>(n,INT_MAX));
        dfs(x,y,maze,mindist,0,destination);
        return mindist[destination[0]][destination[1]] == INT_MAX ? -1 : mindist[destination[0]][destination[1]];
    }
};


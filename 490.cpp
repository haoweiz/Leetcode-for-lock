/*There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.

Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.*/


class Solution {
public:
    bool dfs(int x,int y,vector<vector<bool>> &visited,vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        if(x == destination[0] && y == destination[1])
            return true;
        
        int rowup = x;
        int rowdown = x;
        int colleft = y;
        int colright = y;
        while(rowup-1 >= 0 && maze[rowup-1][y] == 0){
            rowup--;
        }
        if(!visited[rowup][y]){
            visited[rowup][y] = true;
            if(dfs(rowup,y,visited,maze,start,destination))
                return true;
        }
        
        while(rowdown+1 < maze.size() && maze[rowdown+1][y] == 0){
            rowdown++;
        }
        if(!visited[rowdown][y]){
            visited[rowdown][y] = true;
            if(dfs(rowdown,y,visited,maze,start,destination))
                return true;
        }
        
        while(colleft-1 >= 0 && maze[x][colleft-1] == 0){
            colleft--;
        }
        if(!visited[x][colleft]){
            visited[x][colleft] = true;
            if(dfs(x,colleft,visited,maze,start,destination))
                return true;
        }
        
        while(colright+1 < maze[0].size() && maze[x][colright+1] == 0){
            colright++;
        }
        if(!visited[x][colright]){
            visited[x][colright] = true;
            if(dfs(x,colright,visited,maze,start,destination))
                return true;
        }
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return dfs(start[0],start[1],visited,maze,start,destination);
    }
};

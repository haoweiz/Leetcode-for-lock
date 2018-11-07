/*Given a robot cleaner in a room modeled as a grid.

Each cell in the grid can be empty or blocked.

The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.

When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.

Design an algorithm to clean the entire room using only the 4 given APIs shown below.

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}

Example:

Input:
room = [
  [1,1,1,1,1,0,1,1],
  [1,1,1,1,1,0,1,1],
  [1,0,1,1,1,1,1,1],
  [0,0,0,1,0,0,0,0],
  [1,1,1,1,1,1,1,1]
],
row = 1,
col = 3

Explanation:
All grids in the room are marked by either 0 or 1.
0 means the cell is blocked, while 1 means the cell is accessible.
The robot initially starts at the position of row=1, col=3.
From the top left corner, its position is one row below and three columns right.

Notes:

    The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words, you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.
    The robot's initial position will always be in an accessible cell.
    The initial direction of the robot will be facing up.
    All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
    Assume all four edges of the grid are all surrounded by wall.
*/


/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void dfs(int x,int y,int direction,Robot& robot,unordered_set<string> &visited){
        robot.clean();
        visited.insert(to_string(x)+"#"+to_string(y));
        if(direction == 0){
            if(visited.find(to_string(x-1)+"#"+to_string(y)) == visited.end() && robot.move()){
                dfs(x-1,y,0,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x)+"#"+to_string(y-1)) == visited.end() && robot.move()){
                dfs(x,y-1,1,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x+1)+"#"+to_string(y)) == visited.end() && robot.move()){
                dfs(x+1,y,2,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x)+"#"+to_string(y+1)) == visited.end() && robot.move()){
                dfs(x,y+1,3,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
            robot.move();
        }
        else if(direction == 1){
            if(visited.find(to_string(x)+"#"+to_string(y-1)) == visited.end() && robot.move()){
                dfs(x,y-1,1,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x+1)+"#"+to_string(y)) == visited.end() && robot.move()){
                dfs(x+1,y,2,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x)+"#"+to_string(y+1)) == visited.end() && robot.move()){
                dfs(x,y+1,3,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x-1)+"#"+to_string(y)) == visited.end() && robot.move()){
                dfs(x-1,y,0,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
            robot.move();
        }
        else if(direction == 2){
            if(visited.find(to_string(x+1)+"#"+to_string(y)) == visited.end() && robot.move()){
                dfs(x+1,y,2,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x)+"#"+to_string(y+1)) == visited.end() && robot.move()){
                dfs(x,y+1,3,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x-1)+"#"+to_string(y)) == visited.end() && robot.move()){
                dfs(x-1,y,0,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x)+"#"+to_string(y-1)) == visited.end() && robot.move()){
                dfs(x,y-1,1,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
            robot.move();
        }
        else{
            if(visited.find(to_string(x)+"#"+to_string(y+1)) == visited.end() && robot.move()){
                dfs(x,y+1,3,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x-1)+"#"+to_string(y)) == visited.end() && robot.move()){
                dfs(x-1,y,0,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x)+"#"+to_string(y-1)) == visited.end() && robot.move()){
                dfs(x,y-1,1,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
            if(visited.find(to_string(x+1)+"#"+to_string(y)) == visited.end() && robot.move()){
                dfs(x+1,y,2,robot,visited);
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
            robot.move();
        }
    }
    void cleanRoom(Robot& robot) {
        int x = 0;
        int y = 0;
        unordered_set<string> visited;
        int direction = 0;  //0 up, 1 left, 2 down, 3 right
        dfs(x,y,direction,robot,visited);
    }
};

/*Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note: You can only put the bomb at an empty cell.

Example:

Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3 
Explanation: For the given grid,

0 E 0 0 
E 0 W E 
0 E 0 0

Placing a bomb at (1,1) kills 3 enemies.

*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        int result = 0;
        for(int i = 0;i != m;++i){
            for(int j = 0;j != n;++j){
                if(grid[i][j] == 'E'){
                    if(i == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i-1][j]+1;
                }
                else if(grid[i][j] == 'W'){
                    dp[i][j] = 0;
                }
                else{
                    if(i != 0)
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        for(int i = m-1;i >= 0;--i){
            for(int j = 0;j != n;++j){
                if(grid[i][j] != 'W'){
                    if(i != m-1)
                        dp[i][j] = max(dp[i][j],dp[i+1][j]);
                }
            }
        }
        vector<vector<int>> dp2(m,vector<int>(n,0));
        for(int j = 0;j != n;++j){
            for(int i = 0;i != m;++i){
                if(grid[i][j] == 'E'){
                    if(j == 0)
                        dp2[i][j] = 1;
                    else
                        dp2[i][j] = dp2[i][j-1]+1;
                }
                else if(grid[i][j] == 'W'){
                    dp2[i][j] = 0;
                }
                else{
                    if(j != 0)
                        dp2[i][j] = dp2[i][j-1];
                }
            }
        }
        for(int j = n-1;j >= 0;--j){
            for(int i = 0;i != m;++i){
                if(grid[i][j] != 'W'){
                    if(j != n-1)
                        dp2[i][j] = max(dp2[i][j],dp2[i][j+1]);
                }
            }
        }
        for(int i = 0;i != m;++i){
            for(int j = 0;j != n;++j){
                if(grid[i][j] == '0'){
                    result = max(result,dp[i][j]+dp2[i][j]);
                }
            }
        }
        return result;
    }
};

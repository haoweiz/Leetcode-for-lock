/*Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.*/

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int result = 0;
        int m = M.size();
        if(m == 0) return 0;
        int n = M[0].size();
        if(n == 0) return 0;
        vector<vector<vector<int>>> direction(m,vector<vector<int>>(n,vector<int>(4,0)));  //four direction,left,leftup,up,rightup
        for(int j = 0;j != n;++j){
            if(M[0][j] == 1){
                if(j != 0) 
                    direction[0][j][0] = direction[0][j-1][0]+1;
                else
                    direction[0][j][0] = 1;
                direction[0][j][1] = 1;
                direction[0][j][2] = 1;
                direction[0][j][3] = 1;
                result = max(result,direction[0][j][0]);
                result = max(result,direction[0][j][1]);
                result = max(result,direction[0][j][2]);
                result = max(result,direction[0][j][3]);
            }
        }
        for(int i = 1;i != m;++i){
            if(M[i][0] == 1){
                direction[i][0][0] = 1;
                direction[i][0][1] = 1;
                direction[i][0][2] = direction[i-1][0][2]+1;
                if(n == 1)
                    direction[i][0][3] = 1;
                else
                    direction[i][0][3] = direction[i-1][1][3]+1;
                result = max(result,direction[i][0][0]);
                result = max(result,direction[i][0][1]);
                result = max(result,direction[i][0][2]);
                result = max(result,direction[i][0][3]);
            }
            for(int j = 1;j != n;++j){
                if(M[i][j] == 1){
                    if(j == n-1){
                        direction[i][j][3] = 1;
                    }
                    else{
                        direction[i][j][3] = direction[i-1][j+1][3]+1;
                    }
                    direction[i][j][0] = direction[i][j-1][0]+1;
                    direction[i][j][1] = direction[i-1][j-1][1]+1;
                    direction[i][j][2] = direction[i-1][j][2]+1;
                    result = max(result,direction[i][j][0]);
                    result = max(result,direction[i][j][1]);
                    result = max(result,direction[i][j][2]);
                    result = max(result,direction[i][j][3]);
                }
            }
        }
        return result;
    }
};

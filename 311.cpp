/*Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int am = A.size();
        int an = A[0].size();
        int bm = B.size();
        int bn = B[0].size();
        vector<vector<int>> result(am,vector<int>(bn,0));
        vector<vector<int>> vec(am);
        for(int i = 0;i != am;++i){
            for(int j = 0;j != an;++j){
                if(A[i][j] != 0)
                    vec[i].push_back(j);
            }
        }
        for(int i = 0;i != am;++i){
            for(int j = 0;j != vec[i].size();++j){
                for(int k = 0;k != bn;++k)
                    result[i][k] += A[i][vec[i][j]]*B[vec[i][j]][k];
            }
        }
        return result;
    }
};

/*There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5. 

Follow up:
Could you solve it in O(nk) runtime?
*/


/** For O(nk) Solution, record the index of the minimal value and the second minimal value,
the complexity of this solution is O(nk2)
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int m = costs.size();
        if(m == 0) return 0;
        int n = costs[0].size();
        if(n == 0) return 0;
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        for(int j = 0;j != n;++j){
            dp[0][j] = costs[0][j];
        }
        for(int i = 1;i != m;++i){
            for(int j = 0;j != n;++j){
                for(int t = 0;t != n;++t){
                    if(t == j) continue;
                    dp[i][j] = min(dp[i][j],dp[i-1][t]+costs[i][j]);
                }
            }
        }
        int result = INT_MAX;
        for(int j = 0;j != n;++j){
            result = min(result,dp[m-1][j]);
        }
        return result;
    }
};

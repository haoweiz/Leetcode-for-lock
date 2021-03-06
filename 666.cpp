/* If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:

    The hundreds digit represents the depth D of this node, 1 <= D <= 4.
    The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
    The units digit represents the value V of this node, 0 <= V <= 9.

Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.

Example 1:

Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.

Example 2:

Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.
*/

class Solution {
public:
    int pathSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int depth = nums.back()/100;
        int leaves = pow(2,depth-1);
        vector<vector<int>> vec(depth,vector<int>(leaves,-1));
        vector<vector<int>> sum(depth);
        sum[0].push_back(nums[0]%10);
        for(int i = 0;i != nums.size();++i){
            int d = nums[i]/100-1;
            int level = (nums[i]-nums[i]/100*100)/10;
            vec[nums[i]/100-1][level-1] = nums[i];
        }
        for(int i = 1;i != vec.size();++i){
            for(int j = 0;j != vec[i].size();++j){
                if(vec[i][j] != -1)
                    sum[i].push_back(sum[i-1][j/2]+vec[i][j]%10);
                else
                    sum[i].push_back(-1);
            }
        }
        int result = 0;
        for(int i = 0;i != sum.size();++i){
            for(int j = 0;j != sum[i].size();++j){
                if(sum[i][j] != -1){
                    if(i == depth-1 || (sum[i+1][2*j] == -1 && sum[i+1][2*j+1] == -1))
                        result += sum[i][j];
                }
            }
        }
        return result;
    }
};

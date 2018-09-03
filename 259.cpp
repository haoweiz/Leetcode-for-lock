/*Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example:

Input: nums = [-2,0,1,3], and target = 2
Output: 2 
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]
Follow up: Could you solve it in O(n2) runtime?*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int result = 0;
        if(nums.size() <= 2) return 0;
        sort(nums.begin(),nums.end());
        int last = nums.size()-2;
        for(int i = 0;i != last;++i){
            int newtarget = target-nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while(start < end){
                if(nums[start]+nums[end] >= newtarget)
                    end--;
                else{
                    result += (end-start);
                    start++;
                }
            }
        }
        return result;
    }
};

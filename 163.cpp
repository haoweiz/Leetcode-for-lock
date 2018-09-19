/*Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if(nums.empty()){
            if(lower == upper)
                result.push_back(to_string(lower));
            else
                result.push_back(to_string(lower)+"->"+to_string(upper));
            return result;
        }
        if(nums[0] == (int64_t)lower+1)
                result.push_back(to_string(lower));
        else if(nums[0] > (int64_t)lower+1)
                result.push_back(to_string(lower)+"->"+to_string(nums[0]-1));
        for(int i = 1;i != nums.size();++i){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1]+2){
                result.push_back(to_string(nums[i]-1));
            }
            else if(nums[i] > nums[i-1]+2){
                result.push_back(to_string(nums[i-1]+1)+"->"+to_string(nums[i]-1));
            }
        }
        if(nums.back() == (int64_t)upper-1){
            result.push_back(to_string(upper));
        }
        else if(nums.back() < (int64_t)upper-1){
            result.push_back(to_string(nums.back()+1)+"->"+to_string(upper));
        }
        return result;
    }
};

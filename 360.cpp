/*Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example 1:

Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]
Example 2:

Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]*/


class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> result;
        if(a == 0){
            if(b > 0){
                for(int i = 0;i != nums.size();++i){
                    result.push_back(b*nums[i]+c);
                }
                return result;
            }
            else{
                for(int i = nums.size()-1;i >= 0;--i){
                    result.push_back(b*nums[i]+c);
                }
                return result;
            }
        }
        double pivot = -b/(2.0*a);
        if(a > 0){
            int start = -1;
            int end = -1;
            if(nums[0] > pivot){
                for(int i = 0;i != nums.size();++i){
                    result.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
                }
                return result;
            }
            if(nums.back() < pivot){
                for(int i = nums.size()-1;i >= 0;--i){
                    result.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
                }
                return result;
            }
            for(int i = 0;i != nums.size();++i){
                if(nums[i] > pivot){
                    end = i;
                    start = i-1;
                    break;
                }
            }
            while(start >= 0 || end < nums.size()){
                if(start < 0){
                    result.push_back(a*nums[end]*nums[end]+b*nums[end]+c);
                    end++;
                    continue;
                }
                if(end == nums.size()){
                    result.push_back(a*nums[start]*nums[start]+b*nums[start]+c);
                    start--;
                    continue;
                }
                if(pivot-nums[start] < nums[end]-pivot){
                    result.push_back(a*nums[start]*nums[start]+b*nums[start]+c);
                    start--;
                }
                else{
                    result.push_back(a*nums[end]*nums[end]+b*nums[end]+c);
                    end++;
                }
            }
            return result;
        }
        else{
            int start = 0;
            int end = nums.size()-1;
            if(nums[0] > pivot){
                for(int i = nums.size()-1;i >= 0;--i){
                    result.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
                }
                return result;
            }
            if(nums.back() < pivot){
                for(int i = 0;i != nums.size();++i){
                    result.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
                }
                return result;
            }
            while(start <= end){
                if(pivot-nums[start] > nums[end]-pivot){
                    result.push_back(a*nums[start]*nums[start]+b*nums[start]+c);
                    start++;
                }
                else{
                    result.push_back(a*nums[end]*nums[end]+b*nums[end]+c);
                    end--;
                }
            }
            return result;
        }
        return result;
    }
};

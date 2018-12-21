/* Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:

Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.

Note:

    The input array will only contain 0 and 1.
    The length of input array is a positive integer and will not exceed 10,000

Follow up:
What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently? */


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int start = 0;
        int end = 0;
        int countzeros = 0;
        int result = 0;
        while(end != nums.size()){
            if(countzeros == 0){
                if(nums[end] == 0)
                    countzeros++;
            }
            else if(countzeros == 1){
                if(nums[end] == 0){
                    while(nums[start] == 1){
                        start++;
                    }
                    start++;
                }
            }
            end++;
            result = max(result,end-start);
        }
        return result;
    }
};

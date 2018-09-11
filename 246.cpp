/*A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int start = 0;
        int end = num.size()-1;
        while(start <= end){
            if(num[start] == '0' && num[end] == '0'){
                start++;
                end--;
            }
            else if(num[start] == '1' && num[end] == '1'){
                start++;
                end--;
            }
            else if(num[start] == '8' && num[end] == '8'){
                start++;
                end--;
            }
            else if(num[start] == '6' && num[end] == '9'){
                start++;
                end--;
            }
            else if(num[start] == '9' && num[end] == '6'){
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
};

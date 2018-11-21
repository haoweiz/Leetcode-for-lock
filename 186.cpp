/*Given an input string , reverse the string word by word. 

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

Note: 

    A word is defined as a sequence of non-space characters.
    The input string does not contain leading or trailing spaces.
    The words are always separated by a single space.

Follow up: Could you do it in-place without allocating extra space?
*/

class Solution {
public:
    void reverseWords(vector<char>& str) {
        int start = 0;
        int end = str.size()-1;
        while(start < end){
            swap(str[start],str[end]);
            start++;
            end--;
        }
        int begin = 0;
        int pointer = 0;
        while(pointer < str.size()){
            while(pointer < str.size() && str[pointer] != ' '){
                pointer++;
            }
            int finally = pointer-1;
            while(begin < finally){
                swap(str[begin],str[finally]);
                begin++;
                finally--;
            }
            pointer++;
            begin = pointer;
        }
    }
};

/*You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

Example:

Input: s = "++++"
Output: true 
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
*/

class Solution {
public:
    unordered_map<string,bool> um;
    bool canWin(string s) {
        if(um.find(s) != um.end()){
            return um[s];
        }
        bool result = false;
        for(int i = 1;i < s.size();++i){
            if(s[i] == '+' && s[i-1] == '+'){
                s[i] = '-';
                s[i-1] = '-';
                bool flag = canWin(s);
                s[i] = '+';
                s[i-1] = '+';
                if(!flag){
                    result = true;
                    break;
                }
            }
        }
        um[s] = result;
        return result;
    }
};

/* Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:

Given s = "internationalization", abbr = "i12iz4n":

Return true.

Example 2:

Given s = "apple", abbr = "a2e":

Return false.
*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int pointer1 = 0;
        int pointer2 = 0;
        while(pointer1 < word.size() && pointer2 < abbr.size()){
            if(word[pointer1] == abbr[pointer2]){
                pointer1++;
                pointer2++;
            }
            else{
                if(abbr[pointer2] <= '0' || abbr[pointer2] > '9')
                    return false;
                string number = "";
                while(pointer2 != abbr.size() && abbr[pointer2] >= '0' && abbr[pointer2] <= '9'){
                    number += abbr[pointer2];
                    pointer2++;
                }
                int length = atoi(number.c_str());
                pointer1 += length;
            }
        }
        return pointer1==word.size() && pointer2==abbr.size();
    }
};

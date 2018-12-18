/* Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
*/


class StringIterator {
public:
    StringIterator(string compressedString) {
        int n = compressedString.size();
        int pointer = 0;
        while(pointer != n){
            char c = compressedString[pointer];
            pointer++;
            string number = "";
            while(pointer != n && compressedString[pointer]>='0' && compressedString[pointer]<='9'){
                number += compressedString[pointer];
                pointer++;
            }
            int num = atoi(number.c_str());
            vec.push_back(make_pair(c,num));
        }
        position = 0;
        count = 0;
    }
    
    char next() {
        if(position == vec.size())
            return ' ';
        char result = vec[position].first;
        count++;
        while(position != vec.size() && count == vec[position].second){
            count = 0;
            position++;
        }
        return result;
    }
    
    bool hasNext() {
        if(position != vec.size())
            return true;
        return false;
    }
private:
    vector<pair<char,int>> vec;
    int position;
    int count;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

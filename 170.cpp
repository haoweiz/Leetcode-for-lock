/*Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false

Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false

*/

class TwoSum {
public:
    unordered_map<int,int> count;
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        count[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto iter : count){
            int target = value-iter.first;
            if((target == iter.first && iter.second > 1) || (target != iter.first && count.count(target)))
                return true;
        }
        return false;
    }
};
/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */

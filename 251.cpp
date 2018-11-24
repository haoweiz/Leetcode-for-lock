/*Implement an iterator to flatten a 2d vector.

Example:

Input: 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
Output: [1,2,3,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,2,3,4,5,6].

Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

class Vector2D {
public:
    vector<vector<int>>::iterator iter,end;
    int offset = 0;
    Vector2D(vector<vector<int>>& vec2d) {
        iter = vec2d.begin();
        end = vec2d.end();
    }

    int next() {
        int result = (*iter)[offset];
        offset++;
        return result;
    }

    bool hasNext() {
        while(iter != end && offset == (*iter).size()){
            iter++;
            offset = 0;
        }
        return iter != end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

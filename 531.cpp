/*Given a picture consisting of black and white pixels, find the number of black lonely pixels.

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

Example:
Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.
Note:
The range of width and height of the input 2D array is [1,500].*/

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int result = 0;
        int m = picture.size();
        int n = picture[0].size();
        vector<int> countrow(m,0);
        for(int i = 0;i != m;++i){
            int count = 0;
            for(int j = 0;j != n;++j){
                if(picture[i][j] == 'B')
                    count++;
            }
            countrow[i] = count;
        }
        for(int j = 0;j != n;++j){
            int count = 0;
            int row;
            for(int i = 0;i != m;++i){
                if(picture[i][j] == 'B'){
                    count++;
                    row = i;
                }
            }
            if(count == 1 && countrow[row] == 1)
                result++;
        }
        return result;
    }
};

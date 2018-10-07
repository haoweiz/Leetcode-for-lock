/*There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input: 
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
Example 2:
Input: 
flowers: [1,2,3]
k: 1
Output: -1
Note:
The given array will be in the range [1, 20000].*/


class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int N = flowers.size();
        vector<int> position;
        position.push_back(flowers[0]);
        for(int i = 1;i != flowers.size();++i){
            if(flowers[i] > position.back()){
                if(flowers[i] - position.back() == k+1)
                    return i+1;
                position.push_back(flowers[i]);
                continue;
            }
            int start = 0;
            int end = position.size()-1;
            while(start < end){
                int pivot = start + (end-start)/2;
                if(flowers[i] > position[pivot])
                    start = pivot+1;
                else
                    end = pivot;
            }
            if(start == 0){
                if(position[0] - flowers[i] == k+1)
                    return i+1;
            }
            else{
                if(flowers[i] - position[start-1] == k+1 || position[start] - flowers[i] == k+1)
                    return i+1;
            }
            position.insert(position.begin()+start,flowers[i]);
        }
        return -1;
    }
};


class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for(int i=0; i<flowers.size();i++)
            days[flowers[i] - 1] = i + 1;
        int left = 0, right = k + 1, res = INT_MAX;
        for(int i = 0; right < days.size(); i++){
            if(days[i] < days[left] || days[i] <= days[right]){   
                if(i == right)
                    res = min(res, max(days[left], days[right]));
                left = i, right = k + 1 + i;
            }
        }
        return (res == INT_MAX)?-1:res;
    }
};

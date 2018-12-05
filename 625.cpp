/*Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1
Input:

48 

Output:

68

Example 2
Input:

15

Output:

35
*/

//beat 5%
class Solution {
public:
    void backtrace(int a,int64_t product,int64_t number,int &result){
        if(product > INT_MAX || number > INT_MAX)
            return;
        if(product == a){
            result = min(result,(int)number);
            return;
        }
        else if(product > a){
            return;
        }
        for(int i = 2;i <= 9;++i){
            int t = product*i;
            if(a % t == 0)
                backtrace(a,t,10*number+i,result);
        }
    }
    int smallestFactorization(int a) {
        if(a == 1) return 1;
        int result = INT_MAX;
        backtrace(a,1,0,result);
        return result==INT_MAX ? 0 : result;
    }
};

//beat 100%
class Solution {
public:
    int smallestFactorization(int a) {
        if(a == 1) return 1;
        vector<int> factor;
        while(a != 1){
            bool flag = false;
            for(int i = 9;i >= 2;--i){
                if(a%i == 0){
                    flag = true;
                    factor.push_back(i);
                    a /= i;
                    break;
                }
            }
            if(!flag) return false;
        }
        int64_t result = 0;
        for(int i = factor.size()-1;i >= 0;--i){
            result = result*10+factor[i];
            if(result > INT_MAX)
                return 0;
        }
        return result;
    }
};




/*A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

Example:

Input:  n = 2
Output: ["11","69","88","96"]*/



class Solution {
public:
    void dfseven(string str,vector<string> &result,int length){
        if(str.size() == length){
            for(int i = str.size()-1;i >= 0;--i){
                if(str[i] == '0')
                    str += "0";
                else if(str[i] == '1')
                    str += "1";
                else if(str[i] == '6')
                    str += "9";
                else if(str[i] == '8')
                    str += "8";
                else if(str[i] == '9')
                    str += "6";
            }
            result.push_back(str);
            return;
        }
        dfseven(str+"0",result,length);
        dfseven(str+"1",result,length);
        dfseven(str+"6",result,length);
        dfseven(str+"8",result,length);
        dfseven(str+"9",result,length);
    }
    void dfsodd(string str,vector<string> &result,int length){
        if(str.size() == length){
            for(int i = str.size()-2;i >= 0;--i){
                if(str[i] == '0')
                    str += "0";
                else if(str[i] == '1')
                    str += "1";
                else if(str[i] == '6')
                    str += "9";
                else if(str[i] == '8')
                    str += "8";
                else if(str[i] == '9')
                    str += "6";
            }
            result.push_back(str);
            return;
        }
        if(str.size() != length-1){
            dfsodd(str+"6",result,length);
            dfsodd(str+"9",result,length);
        }
        dfsodd(str+"0",result,length);
        dfsodd(str+"1",result,length);
        dfsodd(str+"8",result,length);
    }
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;
        if(n == 0) return result;
        if(n == 1){
            result = vector<string>({"0","1","8"});
            return result;
        }
        if(n % 2 == 0){
            dfseven("1",result,n/2);
            dfseven("6",result,n/2);
            dfseven("8",result,n/2);
            dfseven("9",result,n/2);
            return result;
        }
        else{
            dfsodd("1",result,(n+1)/2);
            dfsodd("6",result,(n+1)/2);
            dfsodd("8",result,(n+1)/2);
            dfsodd("9",result,(n+1)/2);
            return result;
        }
        return result;
    }
};

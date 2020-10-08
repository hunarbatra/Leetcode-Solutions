class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        if(digits.empty()) return "";
        vector<int> diff1 = {1,4,7,2,5,8}, diff2 = {2,5,8,1,4,7};
        int sum = 0;
        unordered_map<int,int> hash; // num -> occurence
        for(int i : digits) {
            sum += i;
            hash[i]++;
        }
        while(sum % 3 != 0) {
            for(int i : sum%3==1 ? diff1 : diff2) {
                if(hash[i] !=0) {
                    hash[i]--;
                    sum -= i;
                    break;
                }
            }
        }
        string result = "";
        for(int i=9; i>=0; i--) {
            result += string(hash[i], '0' + i); //hash[i] times print i
        }
        return result.size() && result[0]=='0' ? "0" : result;
    }
};
/* 
If we sum all digits, and the modulo of 3 is not zero, we need to remove 1 
(preferably) or 2 smallest digits. If modulo 3 of the sum is 1, for example, 
we will try to remove 1, 4, or 7, if exists, or two of 2, 5, or 8.

Time Complexity : O(n)
*/

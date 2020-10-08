class Solution {
public:    
    int myAtoi(string str) {
        long res = 0;
        int sign = 1;
        size_t index = 0;
        if(str.find_first_not_of(' ') != string::npos) index = str.find_first_not_of(' ');
        if(str[index] == '+' || str[index] == '-') sign = str[index++] == '-' ? -1 : 1;

        while(index<str.length() && isdigit(str[index])) {
            res = res * 10 + (str[index++] - '0');
            if(res*sign > INT_MAX) return INT_MAX; //Check for INT_MAX & INT_MIN bounds
            if(res*sign < INT_MIN) return INT_MIN;
        }
        return res*sign;
    }
};
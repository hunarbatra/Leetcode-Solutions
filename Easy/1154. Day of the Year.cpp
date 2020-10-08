class Solution {
public:
    int dayOfYear(string date) {
        if(date.size() != 10) return 0;
        vector<int> months({0,31,28,31,30,31,30,31,31,30,31,30,31});
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        int noOfDays = accumulate(months.begin(), months.begin()+month, 0);
        if(year%4==0 && month>2 && (year%400==0 || year%100!=0)) noOfDays += 1;
        return noOfDays + day;
    }
};  
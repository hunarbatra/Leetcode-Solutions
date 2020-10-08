class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        if(date1 == date2) return 0;
        for(int i = 0; i < date1.length(); i++) if(date1 > date2) {swap(date1, date2); break;}
        if(date1.size() != 10 || date2.size() != 10) return 0;
        int y1, m1, d1, y2, m2, d2;
        y1 = stoi(date1.substr(0, 4)); y2 = stoi(date2.substr(0, 4));
        m1 = stoi(date1.substr(5, 2)); m2 = stoi(date2.substr(5, 2)); 
        d1 = stoi(date1.substr(8, 2)); d2 = stoi(date2.substr(8, 2));
        
        vector<int> months({0,31,28,31,30,31,30,31,31,30,31,30,31});
        int result = 0;
        for(int y=y1; y<y2; y++) {
            result += checkleap(y) ? 366 : 365;
        }
        for(int m=1; m<m1; m++) {
            result -= m==2 ? (checkleap(y1) ? 29 : 28) : months[m];
        }
        for(int m=1; m<m2; m++) {
            result += m==2 ? (checkleap(y2) ? 29 : 28) : months[m];
        }
        return result + d2 - d1;
    }
    
    bool checkleap(int year) {
        if(year%4==0 && (year%400==0 || year%100!=0)) return true;
        return false;
    }
};
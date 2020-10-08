class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // use stable_sort as order of equivalent elements is preserved
        stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b) {
            auto s1 = a.substr(a.find(' ') + 1); // get words not including identifier
            auto s2 = b.substr(b.find(' ') + 1);
            
            // order if a || b are digit-logs
            if(isdigit(s1[0]) && isdigit(s2[0])) return false;
            if(isdigit(s1[0]) && !isdigit(s2[0])) return false;
            if(!isdigit(s1[0]) && isdigit(s2[0])) return true;
            
            // order if a && b are letter logs
            auto diff = s1.compare(s2);
            if(diff) return diff < 0;
            return a.compare(b) < 0;
        });
        return logs;
    }
};
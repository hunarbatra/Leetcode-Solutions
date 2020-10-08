class Solution {
public:
    vector<string> restoreIpAddresses(string s) { //Our Driver
        if(s.size() == 0) return {};
        vector<string> allIP;
        vector<int> path;
        dfs(allIP, path, s, 0, 0);
        return allIP;
    }
    
    void dfs(vector<string>& allIP, vector<int>& path, string s, int index, int segment) {
        if(segment == 4 && index == s.length()) { //Our Goal
            string valid = to_string(path[0])+"."+to_string(path[1])+"."+to_string(path[2])
                            +"."+to_string(path[3]);
            allIP.push_back(valid);
        } else if(segment == 4 && index < s.length() || index > s.length()) return;
        
        for(int len=1; len<=3 && index+len<=s.length(); len++) {
            string current = s.substr(index, len);
            int value = stoi(current);
            if(value > 255 || len>=2 && s[index]=='0') continue; //Our Constraints
            //Our Choice
            path.push_back(value); //1. Choose
            dfs(allIP, path, s, index+len, segment+1); //2. Explore
            path.pop_back(); //3. Unchoose a.k.a restore for the next backtrack
        }
    }
};
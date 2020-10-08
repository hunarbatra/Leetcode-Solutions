class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        if(emails.empty()) return 0;
        unordered_set<string> hashset;
        for(string email : emails) {
            string cleanEmail;
            for(char ch : email) {
                if(ch == '+' || ch == '@') break;
                if(ch == '.') continue;
                cleanEmail += ch;
            }
            cleanEmail += email.substr(email.find('@'));
            hashset.insert(cleanEmail);
        }
        return hashset.size();
    }
};
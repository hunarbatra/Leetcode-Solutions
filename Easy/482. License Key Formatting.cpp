class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        if(S.size() == 0) return "";
        string temp = "", result = "";
        for(int i=0; i<S.size(); ++i) {
            if(S[i] == '-') continue;
            else temp += toupper(S[i]);
        }
        int counter = 0;
        for(int i=temp.size()-1; i>=0; --i) {
            counter++;
            result += temp[i];
            if(counter == K && i!=0) {
                result += '-';
                counter = 0;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
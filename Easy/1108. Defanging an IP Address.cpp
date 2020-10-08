class Solution {
public:
    string defangIPaddr(string address) {
        if(address.length()==0) return "";
        string result = "";
        for(int i=0; i<address.length(); i++) {
            if(address[i]=='.') {
                result += "[.]";
            }
            else {
                result += address[i];
            }
        }
        return result;
    }
};
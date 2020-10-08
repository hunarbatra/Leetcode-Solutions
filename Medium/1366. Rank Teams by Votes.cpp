class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if(votes.size() == 1) return votes[0];
        unordered_map<char, vector<int>> count;
        for(char c : votes[0]) { //initialize hashtable for different letters
            count[c] = vector<int>(votes[0].size(), 0);
        }
        for(string str : votes) { //increment vector for every char found
            for(int i=0; i<str.size(); i++) {
                count[str[i]][i]++;
            }
        }
        string result = votes[0];
        sort(result.begin(), result.end(), [&](auto a, auto b) { //[&] is used to capture references of external variables
            return count[a] == count[b] ? a < b : count[a] > count[b]; //[&] is used to access count[]
        }); //if the vectors are equal, use the letters to sort, 
        //if not equal, use c++ vector inequality to figure out which one wins
        return result; //sort based on power of every index for every char. if its equal for all char, then return lexicographically sorted string
    }
};
/* Eg : "WXYZ", "XYZW"
X->[1,1,0,0] 
W->[1,0,0,1]
Y->[0,1,1,0]
Z->[0,0,1,1]
=> "XWYZ"
*/
// Time : O(vs) -> v=number of votes & s=no of chars in each string
class Solution {
public:
    int numTeams(vector<int>& rating) { //O(N^2)
        if(rating.empty()) return 0;
        int ans = 0;
        for(int j=1; j<rating.size()-1; j++) { //Fixing j's position
            int i_smaller=0, i_larger=0, k_smaller=0, k_larger=0;
            for(int i=0; i<j; i++) { //check towards j's left
                if(rating[i] < rating[j]) i_smaller++;
                else if(rating[i] > rating[j]) i_larger++;
            }
            for(int k=j+1; k<rating.size(); k++) { //check towards j's right
                if(rating[j] < rating[k]) k_larger++;
                else if(rating[j] > rating[k]) k_smaller++;
            }
            ans += i_smaller * k_larger + i_larger * k_smaller;
        }
        return ans;
    }
    
    int numTeams1(vector<int>& rating) { //O(N^3) -> Brute Force
        if(rating.empty()) return 0;
        int num_teams = 0;
        for(int i=0; i<rating.size(); i++) {
            for(int j=i+1; j<rating.size(); j++) {
                for(int k=j+1; k<rating.size(); k++) {
                    if(rating[i] < rating[j] && rating[j] < rating[k] || 
                      rating[i] > rating[j] && rating[j] > rating[k]) 
                        num_teams++;
                }
            }
        }
        return num_teams;
    }
};
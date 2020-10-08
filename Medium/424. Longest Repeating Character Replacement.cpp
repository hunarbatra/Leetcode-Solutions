class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()==0) return 0;
        int low = 0, most_frequent_count = 0, max_length = 1;
        unordered_map<char, int> letters; 
        //sliding window approach
        for(int high = 0; high < s.length(); high++) {
            int current_letter_count = ++letters[s[high]];
            most_frequent_count = max(most_frequent_count, current_letter_count); 
            while(high-low+1-most_frequent_count > k) {
                //move low ahead if current window size - frequent count > number of changes to be made
                //this means that our current window size exceeds the size we can actually handle with
                //raplcements, so we move low++, to make the window shorter, thus, moving ahead
                // and checking the length of other variations of thre window
                letters[s[low]]--;
                low++;
            }
            max_length = max(max_length, high-low+1);
        }
        return max_length;
    }
};
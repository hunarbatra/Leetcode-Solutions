class Solution {
public:
    int arrangeCoins2(int n) { // Naive Solution
        if(n <= 0) return 0;
        int stairs = 1, counter = 0;
        while(n) { // while n != 0, if n becomes 0, then we break from the while loop and return the counter
            n -= stairs++; // decrement the current staircase level from the total number and increment stair lvl
            if(n < 0) return counter; // if we get a negative, return the counter calculated up till now
            counter++; // else increment the counter i.e we have another valid staircase level
        }
        return counter;
        /* Time Complexity :
             Runtime : O(stairs + 1) // this is the number of times we are iterating, we are not iterating O(n) times!!!
             Space : O(1)
        */
    }
};

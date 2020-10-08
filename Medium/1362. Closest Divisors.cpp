class Solution {
public:
    vector<int> closestDivisors(int num) {
        for(int a = sqrt(num+2); a > 0; a--) {
            if((num+1) % a == 0) return {a, (num+1)/a};
            if((num+2) % a == 0) return {a, (num+2)/a};
        }
        return {};
    }
};

/*
Explanation
Iterate a from sqrt(x+2) to 1, and check:
if (x + 1) % a == 0, we directly return the pair [a, (x + 1) / a].
if (x + 2) % a == 0, we directly return the pair [a, (x + 2) / a].
The first valid pair we meet will have be the closet pair.


Complexity
Time O(sqrtX), Space O(1)
*/

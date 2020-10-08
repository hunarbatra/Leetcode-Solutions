class Solution {
public:      
/* Method #1 : Sort by row :
Basically make a vector<string> which will have strings per level
Intialize goingDown to false
if we're on row 0 -> flip goingDown i.e : false->true
if going down is true, we increment current row and more down whilst we're traversing the entire string
Once we reach the last row, we again flip goingDown and make it false
Then we continue upwards and keep on decrementing current row until we reach row 0 where we flip again 
*/
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size() || s.size()==0) return s;
        vector<string> rows(numRows);
        int curr_row = 0;
        bool goingDown = false;
        for(char c : s) { //O(n) -> where n is the number of chars in string s 
            rows[curr_row].push_back(c);
            if(curr_row == 0 || curr_row == numRows - 1)
                goingDown = !goingDown; //flipping goingDown
            curr_row += goingDown ? 1 : -1;
        }
        string result;
        for(string r : rows) { //O(numRows)
            result += r;
        }
        return result;
    } 
};
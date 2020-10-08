class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int A_rotations = check(A[0], A, B);
        if(A_rotations != -1) return A_rotations;
        else return check(B[0], B, A);
    }
    
    int check(int x, vector<int>& A, vector<int>& B) {
        int rot_a = 0, rot_b = 0;
        for(int i=0; i<A.size(); i++) {
            if(A[i] != x && B[i] != x) return -1; //if both could not be rotated;
            else if(A[i] != x) rot_a++; //if A[i]!=x && B[i]==x, rotate b upwards to a
            else if(B[i] != x) rot_b++; //if A[i]==x && B[i]!=x, rotate a downwards to b
        }
        return min(rot_a, rot_b);
    }
};
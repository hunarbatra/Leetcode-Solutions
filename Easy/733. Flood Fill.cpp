class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image; //edge case
        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    void fill(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        if(i<0||j<0||i>image.size()-1||j>image[0].size()-1) return;
        if(image[i][j] != oldColor) return;
        image[i][j] = newColor;
        fill(image, i-1, j, oldColor, newColor); //up
        fill(image, i+1, j, oldColor, newColor); //down
        fill(image, i, j-1, oldColor, newColor); //left
        fill(image, i, j+1, oldColor, newColor); //right
    }
};
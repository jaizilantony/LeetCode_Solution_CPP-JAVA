class Solution {
    void dfs(int i, int j, int oldColor, int newColor, vector<vector<int>>& img) {
        if (i < 0 || i >= img.size() || j < 0 || j >= img[0].size() ||
            img[i][j] != oldColor) {
            return;
        }

        img[i][j] = newColor;

        dfs(i - 1, j, oldColor, newColor, img);
        dfs(i + 1, j, oldColor, newColor, img);
        dfs(i, j - 1, oldColor, newColor, img);
        dfs(i, j + 1, oldColor, newColor, img);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        
        if (oldColor == color)
            return image;

        dfs(sr, sc, oldColor, color, image);

        return image;
    }
};
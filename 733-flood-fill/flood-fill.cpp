class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int iniColor, int color){

        int m = image.size();
        int n = image[0].size();

        //base case
        if(sr < 0 || sc < 0 || sr >= m || sc >= n || image[sr][sc] != iniColor)
            return;

        image[sr][sc] = color;

        dfs(image, sr - 1, sc, iniColor, color);
        dfs(image, sr, sc + 1, iniColor, color);
        dfs(image, sr + 1, sc, iniColor, color);
        dfs(image, sr, sc - 1, iniColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int iniColor = image[sr][sc];

        if(iniColor == color)
            return image;
        
        dfs(image, sr, sc, iniColor, color);

        return image;
    }
};
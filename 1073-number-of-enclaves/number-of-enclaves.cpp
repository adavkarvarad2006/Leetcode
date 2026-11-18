class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &changes){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        changes++;

        dfs(grid, i-1, j, changes);
        dfs(grid, i, j+1, changes);
        dfs(grid, i+1, j, changes);
        dfs(grid, i, j-1, changes);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int total1 = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    total1++;
            }
        }

        int changes = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && grid[i][j] == 1)
                    dfs(grid, i, j, changes);
            }
        }

        return total1 - changes;
    }
};
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int row[] = {0,1,0,-1};
        int col[] = {1,0,-1,0};

        vector<vector<int>> grid(m, vector<int> (n,0));

        for(auto w:walls){
            grid[w[0]][w[1]] = 1;
        }

        for(auto g:guards){
            grid[g[0]][g[1]] = 2;
        }

        for(auto g:guards){

            for(int i=0; i<4; i++){

                int x = g[0] + row[i];
                int y = g[1] + col[i];

                while(x >= 0 && x < m && y >= 0 && y < n){
                    if(grid[x][y] == 1 || grid[x][y] == 2){
                        break;
                    }
                    
                    grid[x][y] = 3;

                    x += row[i];
                    y += col[i];
                }
            }
        }

        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0)
                    ans++;
            }
        }

        return ans;
    }
};
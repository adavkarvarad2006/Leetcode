class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++){
            vector<bool> visited(n+1, false);
            for(int j=0; j<n; j++){
                int a = matrix[i][j];
                if(a < 1 || a > n){
                    return false;
                }
                if(visited[a] == true){
                    return false;
                }
                visited[a] = true;
            }
        }

        for(int i=0; i<n; i++){
            vector<bool> visited(n+1, false);
            for(int j=0; j<n; j++){
                int a = matrix[j][i];
                if(a < 1 || a > n){
                    return false;
                }
                if(visited[a] == true){
                    return false;
                }
                visited[a] = true;
            }
        }

        return true;
    }
};
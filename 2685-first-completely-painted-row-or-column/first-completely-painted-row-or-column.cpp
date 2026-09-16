class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> mp;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowCount(m);
        vector<int> colCount(n);

        for(int i=0; i<arr.size(); i++){
            int a = arr[i];
            int row = mp[a].first;
            int col = mp[a].second;

            rowCount[row]++;
            colCount[col]++;

            if(rowCount[row] == n){
                return i;
            }

            if(colCount[col] == m){
                return i;
            }
        }

        return -1;
    }
};
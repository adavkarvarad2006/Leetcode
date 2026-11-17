class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n, false);
        int ans = 0;

        for(int i=0; i<n; i++){

            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int j=0; j<n; j++){
                        if(!visited[j] && isConnected[node][j] == 1){
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }

                ans++;
            }
        }

        return ans;
    }
};
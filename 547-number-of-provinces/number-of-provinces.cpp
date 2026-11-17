class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_set<int> s;
        int ans = 0;

        for(int i=0; i<n; i++){
            s.insert(i);
        }

        while(!s.empty()){
            int element = *s.begin();
            s.erase(element);
            vector<bool> visited(n, false);

            queue<int> q;

            q.push(element);

            while(!q.empty()){

                int i = q.front();
                q.pop();
                visited[i] = true;

                for(int j=0; j<n; j++){
                    if(i != j && !visited[j] && isConnected[i][j] == 1){
                        q.push(j);
                        s.erase(j);
                    }
                }
            }

            ans++;
        }

        return ans;
    }
};
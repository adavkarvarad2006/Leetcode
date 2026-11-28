class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        vector<int> dist(n, -1);

        for(int i=0; i<n; i++){
            int d = abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1]);

            if(d <= drones[i][2]){
                dist[i] = d;
            }
        }

        int ans = -1;
        int minDist = INT_MAX;

        for(int i=0; i<n; i++){
            if(dist[i] != -1 && dist[i] < minDist){
                ans = i;
                minDist = dist[i];
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> need(n);

        for(int i=0; i<n; i++){
            need[i] = capacity[i]-rocks[i];
        }

        sort(need.begin(), need.end());

        int count = 0;
        int i = 0;
        while(additionalRocks > 0 && i < n){
            if(need[i] <= additionalRocks){
                additionalRocks -= need[i];
                count++;
            }
            i++;
        }

        return count;
    }
};
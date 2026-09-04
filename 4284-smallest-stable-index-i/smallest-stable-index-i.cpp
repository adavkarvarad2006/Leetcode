class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int ma=nums[i], mi=nums[i];

            for(int j=0; j<i; j++){
                ma = max(nums[j], ma);
            }
            for(int k=i+1; k<n; k++){
                mi = min(nums[k], mi);
            }

            if(ma - mi <= k){
                return i;
            }
        }

        return -1;
    }
};
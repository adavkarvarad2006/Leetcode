class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);

        for(auto it:queries){
            int l = it[0];
            int r = it[1];

            diff[l]++;
            diff[r+1]--;
        }

        int sum = 0;

        for(int i=0; i<n-1; i++){
            diff[i+1] += diff[i];
           
        }

        for(int i=0; i<n; i++){
            if(nums[i] > diff[i]){
                return false;
            }
        }

        return true;
    }
};
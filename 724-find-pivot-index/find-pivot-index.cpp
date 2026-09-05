class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int tsum = 0;

        for(int i=0; i<n; i++){
            tsum = tsum + nums[i];
        }

        int lsum =0, rsum=0;

        for(int i=0; i<n; i++){
            rsum = tsum - nums[i] - lsum;

            if(rsum == lsum){
                return i;
            }

            lsum = nums[i] + lsum;
        }

        
        return -1;
    }
};
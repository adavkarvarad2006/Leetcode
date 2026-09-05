class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();

        int tsum = 0;

        for(int i=0; i<n; i++){
            tsum += nums[i];
        }

        int rsum = tsum, lsum = 0;

        for(int i=0; i<n; i++){
            rsum = rsum - nums[i];

            if(rsum == lsum){
                return i;
            }

            lsum += nums[i];
        }

        return -1;
    }
};
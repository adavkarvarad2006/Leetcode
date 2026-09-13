class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());

        long long tsum = 0;

        for(int i=0; i<k; i++){
            long long a = 0;
            if(mul > 0){
                a = (long long)nums[i]*mul;
                mul--;
            }
            else{
                a = (long long)nums[i];
            }

            tsum += a;
        }

        return tsum;
    }
};
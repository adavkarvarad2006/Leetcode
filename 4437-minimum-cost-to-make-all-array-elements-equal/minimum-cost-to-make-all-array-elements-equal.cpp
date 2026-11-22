class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        
        long long ans = LLONG_MAX;

        int left = 0;

        while(left < n){
            int right = left;

            while(right + 1 < n && nums[right + 1] == nums[left])
                right++;

            long long cost = LLONG_MAX;

            if(left == 0 && right == n-1)
                cost = 0;
            else if(left == 0 && right > 0){
                //only suffix operation is needed
                cost = 1LL * (n - right - 1) * nums[left];
            }
            else if(right == n-1 && left < n-1){
                //only prefix operation is needed
                cost = 1LL * left * nums[left];
            }
            else if(left > 0 && right < n-1){
                //Both prefix and suffix operations
                cost = 1LL * (n - (right - left + 1)) * nums[left];
            }

            ans = min(ans, cost);

            left = right + 1;
        }

        return ans;
    }
};
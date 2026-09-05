class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> right(n);
        right[n-1] = nums[n-1];

        //min nikalo
        for(int i=n-2; i>=0; i--){
            right[i] = min(right[i+1], nums[i]);
        }

        int left = 0;

        //max
        for(int i=0; i<n; i++){
            left = max(nums[i], left);

            if(left - right[i] <= k){
                return i;
            }
        }

        return -1;
    }
};
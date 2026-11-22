class Solution {
public:
    int countDominantElements(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return 1;

        int ans = 0;

        for(int i=0; i<n; i++){
            int count = 0;
            int sum = 0;

            if(i > 0){
                sum += nums[i-1];
                count++;
            }

            if(i < n-1){
                sum += nums[i+1];
                count++;
            }

            if(nums[i] * count >= sum)
                ans++;
        }

        return ans;
    }
};
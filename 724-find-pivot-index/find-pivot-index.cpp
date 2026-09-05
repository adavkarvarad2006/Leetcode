class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> s(n);
        s[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            s[i] = s[i+1] + nums[i];
        }

        int left;
        left = 0;

        for(int i=0; i<n; i++){
            left = left + nums[i];

            if(left == s[i]){
                return i;
            }
        }

        return -1;
    }
};
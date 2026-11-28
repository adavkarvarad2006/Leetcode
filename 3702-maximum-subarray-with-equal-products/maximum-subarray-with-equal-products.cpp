class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        
        int len = 1;

        const long long MAX_PROD = 25200;

        for(int i=0; i<n; i++){
            long long l = nums[i];
            long long g = nums[i];
            long long p = nums[i];

            for(int j=i+1; j<n; j++){
                p *= nums[j];

                if(p > MAX_PROD)
                    break;

                l = lcm(l, (long long)nums[j]);
                g = gcd(g, (long long)nums[j]);

                if(p == l*g)
                    len = max(len, j-i+1);
            }
        }

        return len;
    }
};
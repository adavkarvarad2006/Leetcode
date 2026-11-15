class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long ans = 0;

        int even = 1;
        int odd = 0;

        int parity = 0;

        for(int num : arr){
            parity = (parity + num) % 2;

            if(parity == 1){
                ans = (ans + even) % MOD;
                odd++;
            }
            else{
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans;
    }
};
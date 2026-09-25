class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;

        // dp[a][l]
        // a = number of A's used (0 or 1)
        // l = consecutive L's at the end (0, 1, 2)
        long long dp[2][3] = {};

        dp[0][0] = 1;

        for(int i=0; i<n; i++){
            long long ndp[2][3] = {};

            for(int a=0; a<=1; a++){
                for(int l=0; l<=2; l++){
                    long long ways = dp[a][l];

                    if(ways == 0) continue;

                    //Add P
                    ndp[a][0] = (ndp[a][0] + ways) % MOD;

                    //Add L
                    if(l < 2)
                        ndp[a][l+1] = (ndp[a][l+1] + ways) % MOD;

                    //Add A
                    if(a < 1)
                        ndp[a+1][0] = (ndp[a+1][0] + ways) % MOD;
                }
            }

            //Move to next day
            for(int a=0; a<=1; a++)
                for(int l=0; l<=2; l++)
                    dp[a][l] = ndp[a][l];
        }

        long long ans = 0;

        for(int a = 0; a <= 1; a++) {
            for(int l = 0; l <= 2; l++) {
                ans = (ans + dp[a][l]) % MOD;
            }
        }

        return ans;
    }
};
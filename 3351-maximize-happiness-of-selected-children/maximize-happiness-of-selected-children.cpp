class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), [](int a, int b){
            return a > b;
        });

        long long ans = 0;
        int count = 0;

        for(int i=0; i<k; i++){
            happiness[i] -= count;
            if(happiness[i] <= 0) break;
            ans += happiness[i];
            count++;
        }

        return ans;
    }
};
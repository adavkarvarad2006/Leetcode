class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long minCost1 = 1LL * max(need1, need2) * costBoth;

        long long minCost2 = 1LL * (1LL * cost1 * need1 + 1LL * cost2 * need2);

        int mini = min(need1, need2);
        long long minCost3;

        if(mini == need1)
            minCost3 = 1LL * (1LL * costBoth * mini + 1LL * (need2 - need1) * cost2);
        else
            minCost3 = 1LL * (1LL * costBoth * mini + 1LL * (need1 - need2) * cost1);

        long long ans = min({minCost1, minCost2, minCost3});

        return ans;
    }
};
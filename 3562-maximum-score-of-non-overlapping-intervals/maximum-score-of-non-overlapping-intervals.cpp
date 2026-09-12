class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending position
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        // Find previous non-overlapping interval
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i - 1;
            int ans = -1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                // end < current start
                if (a[mid][1] < a[i][0]) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            prev[i] = ans;
        }

        // dp[i][k] = {maximum score, chosen original indices}
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        auto better = [](pair<long long, vector<int>>& x,
                         pair<long long, vector<int>>& y) {
            if (x.first != y.first)
                return x.first > y.first;

            return lexicographical_compare(
                x.second.begin(), x.second.end(),
                y.second.begin(), y.second.end()
            );
        };

        for (int i = 1; i <= n; i++) {

            // Option 1: don't take current interval
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
            }

            // Option 2: take current interval
            int p = prev[i - 1];

            for (int k = 1; k <= 4; k++) {

                pair<long long, vector<int>> candidate;

                candidate.first =
                    a[i - 1][2] + dp[p + 1][k - 1].first;

                candidate.second =
                    dp[p + 1][k - 1].second;

                candidate.second.push_back((int)a[i - 1][3]);

                // We need indices in increasing order
                sort(candidate.second.begin(),
                     candidate.second.end());

                if (better(candidate, dp[i][k])) {
                    dp[i][k] = candidate;
                }
            }
        }

        return dp[n][4].second;
    }
};
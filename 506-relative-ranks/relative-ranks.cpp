class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int , int> mp;

        for(int i=0; i<n; i++){
            mp[score[i]] = i;
        }

        sort(score.begin(), score.end(), greater<int>());

        int cnt = 1;
        vector<string> ans(n);

        for(int it : score){
            if(cnt == 1)
                ans[mp[it]] = "Gold Medal";
            else if(cnt == 2)
                ans[mp[it]] = "Silver Medal";
            else if(cnt == 3)
                ans[mp[it]] = "Bronze Medal";
            else
                ans[mp[it]] = to_string(cnt);
            
            cnt++;
        }

        return ans;
    }
};
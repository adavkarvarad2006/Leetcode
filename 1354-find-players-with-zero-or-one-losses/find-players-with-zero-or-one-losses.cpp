class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;

        for(auto &match : matches){
            int winner = match[0];
            int loser = match[1];

            // Winner has played, so make sure he exists
            if(!mp.count(winner)){
                mp[winner] = 0;
            }

            // Loser has one more loss
            mp[loser]++;
        }

        vector<int> zeroLoss;
        vector<int> oneLoss;

        for(auto it : mp){
            if(it.second == 0){
                zeroLoss.push_back(it.first);
            }
            else if(it.second == 1){
                oneLoss.push_back(it.first);
            }
        }

        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());

        return {zeroLoss, oneLoss};
    }
};
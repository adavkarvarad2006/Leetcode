class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        for(auto it:mp){
            if((it.second.size() == 3) && (it.second[1] - it.second[0] == it.second[2] - it.second[1])){
                ans++;
            }
        }

        return ans;
    }
};
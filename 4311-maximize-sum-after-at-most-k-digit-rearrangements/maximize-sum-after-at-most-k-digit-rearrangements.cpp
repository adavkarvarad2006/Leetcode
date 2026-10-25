class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;

        vector<int> gain;

        for(int num : nums){
            ans += num;

            string temp = to_string(num);
            sort(temp.rbegin(), temp.rend());

            int newNum = stoi(temp);
            gain.push_back(newNum - num);
        }

        sort(gain.rbegin(), gain.rend());

        for(int i=0; i<k; i++){
            ans += gain[i];
        }

        return ans;
    }
};
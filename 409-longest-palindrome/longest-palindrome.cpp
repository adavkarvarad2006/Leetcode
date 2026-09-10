class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for(auto it:s){
            mp[it]++;
        }

        int count = 0;
        bool flag = false;

        for(auto it:mp){
            if(it.second%2 == 0)
                count += it.second;

            if(it.second%2 == 1){
                if(flag == false){
                    count += it.second;
                    flag = true;
                }
                else{
                    count += it.second - 1;
                }
            }
        }

        return count;
    }
};
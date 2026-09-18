class Solution {
public:
    vector<int> findAnagrams(string s, string p){
        int n = p.length();

        vector<int> ans;

        unordered_map<char, int> mp, temp;
        for(char c:p)
            mp[c]++;

        for(int i=0; i<s.length(); i++){
            temp[s[i]]++;

            if(i >= n){
                temp[s[i-n]]--;
                if(temp[s[i-n]] == 0)
                    temp.erase(s[i-n]);
            }

            if(i >= n-1 && mp == temp){
                ans.push_back(i-n+1);
            }
        }

        return ans;
    }
};
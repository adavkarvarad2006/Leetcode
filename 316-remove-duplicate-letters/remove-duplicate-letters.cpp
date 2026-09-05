class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        vector<bool> used(26, false);

        for(int i=0; i<s.size(); i++){
            last[s[i] - 'a'] = i;
        }

        string ans;

        for(int i=0; i<s.size(); i++){
            int ch = s[i];

            if(used[ch - 'a']){
                continue;
            }

            while(!ans.empty() && ans.back() > ch && last[ans.back() - 'a'] > i){
                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            used[ch - 'a'] = true;
        }

        return ans;
    }
};
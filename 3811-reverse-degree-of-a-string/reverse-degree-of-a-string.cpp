class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int x;

        for(int i=0; i<s.size(); i++){
            x = abs(s[i] - 'z') + 1;
            ans += x*(i+1);
        }

        return ans;
    }
};
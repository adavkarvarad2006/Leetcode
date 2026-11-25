class Solution {
public:
    long long countValidSubstrings(string s) {

        int n = s.size();
        long long ans = 0;

        int lastBad = -1;

        for(int r=0; r<n; r++){
            //check whether "abc" ends at index r
            if(r >= 2 && s[r-2] == 'a' && s[r-1] == 'b' && s[r] == 'c'){
                lastBad = r-2;
            }

            ans += (r - lastBad);
        }

        return ans;
    }
};
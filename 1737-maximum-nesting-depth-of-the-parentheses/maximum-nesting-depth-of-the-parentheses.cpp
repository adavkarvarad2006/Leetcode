class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, count = 0;

        for(char it:s){
            if(it == '(')
                count++;
            else if(it == ')')
                count--;
            else
                continue;
            
            ans = max(ans, count);
        }

        return ans;
    }
};
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int n = s.length();

        int depth = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '(')
                depth++;
            else if(s[i] == ')' && i < n-1 && s[i+1] == ')'){
                if(depth > 0){
                    depth--;
                }
                else{
                    //need to add '('
                    ans++;
                }

                i++;
            }
            else{
                //(s[i] == ')' && i < n-1 && s[i+1] == '(') or (s[i] == ')' && i == n-1)
                if(depth > 0){
                    depth--;
                    //need to add ')'
                    ans++;
                }
                else{
                    //need to add '(' and ')' both
                    ans += 2;
                }
            }
        }

        if(depth > 0)
            ans += 2*depth;

        return ans;
    }
};
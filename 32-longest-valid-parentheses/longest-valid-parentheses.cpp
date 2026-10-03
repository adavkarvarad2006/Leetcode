class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;

        int left = 0;
        int right = 0;

        //left to right
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(')
                left++;
            else
                right++;

            if(left == right)
                ans = max(ans, right*2);

            if(right > left){
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;

        //right to left
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] == '(')
                left++;
            else
                right++;

            if(left == right)
                ans = max(ans, left*2);

            if(left > right){
                left = 0;
                right = 0;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int countCommas(int n) {
        int ans = n;

        if(ans < 1000){
            return 0;
        }
        else{
            return ans-999;
        }
    }
};
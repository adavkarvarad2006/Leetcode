class Solution {
public:
    int fib(int n) {
        int one = 0;
        int two = 1;
        int ans = 0;

        if(n == 0) return 0;
        if(n == 1) return 1;

        for(int i=2; i<=n; i++){
            ans = one + two;
            one = two;
            two = ans;
        }

        return ans;
    }
};
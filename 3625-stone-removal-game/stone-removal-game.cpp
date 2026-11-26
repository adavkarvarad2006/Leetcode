class Solution {
public:
    bool canAliceWin(int n) {

        int i;

        for(i=10; i>0; i--){
            if(i > n){
                break;
            }

            n -= i;
        }

        if(i % 2 == 0)
            return false;
        
        return true;
    }
};
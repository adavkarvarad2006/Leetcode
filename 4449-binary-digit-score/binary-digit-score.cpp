class Solution {
public:
    string decimalToBinary(int n){
        if(n == 0)
            return "0";

        string binaryStr = "";

        while(n > 0){
            binaryStr += to_string(n % 2);
            n /= 2;
        }

        reverse(binaryStr.begin(), binaryStr.end());

        return binaryStr;
    }

    int calculateScore(int a, int b) {
        string first = decimalToBinary(a);
        string second = decimalToBinary(b);

        int c1 = 0, c2 = 0;

        for(char c : first){
            if(c == '1')
                c1++;
        }

        for(char c : second){
            if(c == '1')
                c2++;
        }

        if(c1 >= c2)
            return c1*c2;
        else
            return c2/c1;
    }
};
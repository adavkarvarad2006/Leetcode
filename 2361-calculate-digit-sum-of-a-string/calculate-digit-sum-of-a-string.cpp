class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size() > k){
            string curr_s = "";
            for(int i=0; i<s.size(); i += k){
                int curr_sum = 0;
                int end = min((int)s.size(), i+k);

                for(int j=i; j < end; j++){
                    curr_sum += s[j] - '0';
                }

                curr_s += to_string(curr_sum);
            }

            s = curr_s;
        }

        return s;
    }
};
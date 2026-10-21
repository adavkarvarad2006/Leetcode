class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Check if the string is already sorted
        if(is_sorted(s.begin(), s.end())){
            return 0;
        }

        // Cannot sort a reversed string of length 2
        // because the entire string cannot be selected
        if(n == 2){
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Minimum character is at the start, or maximum character is at the end
        if(s[0] == mn || s[n-1] == mx){
            return 1;
        }

        // Check whether minimum or maximum character exists in the middle
        for(int i=1; i<n-1; i++){
            if(s[i] == mn || s[i] == mx){
                return 2;
            }
        }

        // Otherwise, 3 operations are needed
        return 3;
    }
};
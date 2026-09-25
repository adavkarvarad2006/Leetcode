class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {

        long long total = 0, rem = 0, maxi = 0;
        
        for(int i=0; i<milestones.size(); i++){
            total += milestones[i];
            maxi = max(maxi, (long long)milestones[i]);
        }

        rem = total - maxi;

        return min(total, rem*2 + 1);
    }
};
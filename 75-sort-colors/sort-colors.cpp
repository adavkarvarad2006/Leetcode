class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1){
                mid++;
            }

            else{
                //nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// brute force - 
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         for(int i=0; i<nums.size()-1; i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i] > nums[j]){
//                     swap(nums[i], nums[j]);
//                 }
//             }
//         }
//     }
// };
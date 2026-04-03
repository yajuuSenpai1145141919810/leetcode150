// 80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 一樣用雙指標
        int slow=1;
        for(int fast=2;fast<nums.size();fast++){
            if(nums[fast]!=nums[fast-2]){
                nums[slow]=nums[fast];
                slow++;
            }
        }        
        return slow;
    }
};

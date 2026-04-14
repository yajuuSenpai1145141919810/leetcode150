// 26. Remove Duplicates from Sorted Array
// 對照27題
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 如果要往後找我要的東西放到前面 用雙指標

        int slow=0;
        for(int fast=1;fast<nums.size();fast++){
            if(nums[fast]>nums[slow]){
                slow++;
                nums[slow]=nums[fast];
            }
        }
        // [1,2,3] 一開始slow是在0喔,兩輪做完後 slow=2,但共有三個元素所以要+1
        return slow+1;        
    }
};


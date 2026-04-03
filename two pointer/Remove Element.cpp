// 27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 把陣列裡所有不是 val 的數字通通推到最左邊，然後告訴我總共有幾個，剩下的我不管
        int slow=0;
        for(int fast=0;fast<nums.size();fast++){
            if(val!=nums[fast]){
                nums[slow]=nums[fast];
                slow++;
            }
            // 這裡不要fast++; 迴圈已經有了!!!
        }
        
        return slow;
    }
};

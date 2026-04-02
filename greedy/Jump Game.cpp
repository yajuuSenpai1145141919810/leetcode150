// 55. Jump Game
// You are given an integer array nums. You are initially positioned at the array's first index, 
// and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.
// Input: nums = [2,3,1,1,4] Output: true
// Input: nums = [3,2,1,0,4] Output: false

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 要用 Greedy：
        // 因為它不關心你「怎麼跳」的（不需要列出 [0 -> 2 -> 4] 這種路徑）， 它只關心「能不能到」。
        int n=nums.size();
        int far=0;
        for(int i=0;i<n;i++){
            // 先看我目前是否已經超過可走的最遠距離 32104 i=4,far=3 代表你目前已經走超過最遠距離
            if(i>far) return false;
            far=max(far,i+nums[i]);
            if(far>=n-1) return true;

        }
        return false;
    }
};

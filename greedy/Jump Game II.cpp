// 45. Jump Game II

// Each element nums[i] represents the maximum length of a forward jump from index i. 
// In other words, if you are at index i, you can jump to any index (i + j) where:

// 0 <= j <= nums[i] and i + j < n
// Return the "minimum number of jumps" to reach index n - 1. The test cases are generated such that you can reach index n - 1.
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

// "minimum number of jumps"想到用greedy

class Solution {
public:
    int jump(vector<int>& nums) {
        // "minimum number of jumps"想到用greedy

        // 簡單來說就是nums = [2,3,1,1,4],則nums[0]=2,我目前可走到nums[2]因此就第一輪來說
        // 讓nums[0],nums[1],nums[2]找出可以跳的最遠距離,也就是nums[3]=1 ,並把他更新給current
        // 此時current=4>=n-1 所以返回跳兩次

        int n=nums.size();
        int current=0;// 我這一輪能走幾次num[0]=2,就0,1,2三次 
        int far=0; // 紀錄這一輪最遠能到哪裡
        int jump=0;

        for(int i=0;i<n-1;i++){
            far=max(far,i+nums[i]);
            if(i==current){
                jump++;
                current=far;
            }
            if(current>=n-1) return jump;
        }
        return jump;
    }
};

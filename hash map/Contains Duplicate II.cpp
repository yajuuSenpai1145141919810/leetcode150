// 219. Contains Duplicate II
// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
// Input: nums = [1,0,1,1], k = 1
// Output: true

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n=nums.size();

        unordered_map<int,int> mapp;
        // 以[1,0,1,1],,k=1為例子
        // 數字1存在0,數字2存在1位子,數字1在位置2找到但她距離大於1
        // 我就把數字1存在位置2 最後數字1 距離=1ok
        for(int i=0;i<n;i++){
            if(mapp.find(nums[i])!=mapp.end()){
                if(abs(i-mapp[nums[i]])<=k){
                    return true;
                }
            }
            mapp[nums[i]]=i;
        }
        return false;

    }
};

// 189. Rotate Array
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();

        // 重點在這邊 避免轉過頭
        k=k%n;

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);// ex:nums.begin() + 3 指向索引 3 (數字 4)
        reverse(nums.begin()+k,nums.end());

    }
};

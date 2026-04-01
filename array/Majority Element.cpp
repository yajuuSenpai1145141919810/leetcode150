// 169. Majority Element
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Input: nums = [3,2,3]
// Output: 3

// 技巧Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0; // 目前的候選人
        int count=0;  // 候選人的票數
        for(int x:nums){
            // 當血量歸零，表示之前的數字都互相抵銷了，換下一個數字當候選人
            if(count==0){
                candidate=x;
            }
            if(x==candidate){
                count++;
            }else{
                count--;
            }
        }
        return candidate;
    }
};

// 另一種寫法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();
        
        for (int num : nums) {
            counts[num]++;
            // 只要過半了，就可以直接回傳
            if (counts[num] > n / 2) {
                return num;
            }
        }
        return -1; // 理論上不會執行到這
    }
};

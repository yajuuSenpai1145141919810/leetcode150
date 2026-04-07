// 167. Two Sum II - Input Array Is Sorted
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Sorted in non-decreasing order-> 雙指標
        // Two numbers... add up to a specific target也是

        // !!!!Use only constant extra space 所以不能用hash map o(n)

        // 因為這題已經排序 就正常抓左右邊就好
        vector<int> result;

        int n=numbers.size();
        int slow=0;
        int fast=n-1;

        while(slow<fast){
            int sum=numbers[slow]+numbers[fast];
            if(sum==target) return {slow+1,fast+1};

            if(sum<target) slow++;
            if(sum>target) fast--;

        }
        return  {};        
    }
};

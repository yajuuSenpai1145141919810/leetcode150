// 238. Product of Array Except Self
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// 我自己先寫用除法的
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 不能用除法喔
        
        // 看一下 如果答案要長這樣Output: [24,12,8,6]
        vector<int>  answer;
        int n=nums.size();

        int count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                count++;
            }
            if(count>=2){
                //  這裡要先 assign 空間才能回傳，因為你的 answer 原本是空的
                answer.assign(n,0);
                return answer;
            }
        }

        int temp=1; // 不能設0這是乘法
        int temp1=0;
        for(int k=0;k<n;k++){
            if(nums[k]!=0){
                temp*=nums[k];
            }
        }

        for(int i=0;i<n;i++){
            if(count==1){// 我在想要怎麼處理[0,0,9,0,0]的情況  就跟全都非0的一起跑 再用if else分開就好
                if(nums[i]==0){
                    answer.push_back(temp);

                }else{
                    answer.push_back(0);
            
                }
            }else{
                answer.push_back(temp/nums[i]);
            }
        }
        return answer;
    }
};

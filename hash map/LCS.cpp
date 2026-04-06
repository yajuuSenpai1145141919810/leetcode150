// 128. Longest Consecutive Sequence
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// Input: nums = [1,0,1,2]
// Output: 3


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 核心技巧 只有「左邊沒人」的人，才有資格往後數。 用set會比較快
        int n=nums.size();
        unordered_set<int> mapp;
        if(nums.empty()) return 0;
        for(int i=0;i<n;i++){
            mapp.insert(nums[i]); // set可以用insert
        }

        int maxlen=1;

        // 語法問題 for(int j=0; j < mapp.size(); j++){  不能這樣寫
        // mapp[j] <--- 這是錯的！set 不能用 [ ] 抓資料
        
        for(int num:mapp){
            if(!mapp.count(num-1)){
                int count=1;
                int cur=num; // 如果沒有寫 單純用while(mapp.count(nums[j]+1)) 就會一直原地找 所以設一個參數
                while(mapp.count(cur+1)){
                    count++;
                    cur++;
                }

                maxlen=max(count,maxlen);
            }
        }
        return maxlen;        
    }
};


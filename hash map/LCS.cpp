// 128. Longest Consecutive Sequence
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// Input: nums = [1,0,1,2]
// Output: 3

// 正確但會tle

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 核心技巧 只有「左邊沒人」的人，才有資格往後數。 用set會比較快
        int n=nums.size();
        unordered_set<int> mapp;

        if(nums.empty()) return 0;

        for(int i=0;i<n;i++){
            mapp.insert(nums[i]);
        }

        int maxlen=1;

        for(int j=0;j<n;j++){
            if(!mapp.count(nums[j]-1)){
                int count=1;
                int cur=nums[j]; // 如果沒有寫 單純用while(mapp.count(nums[j]+1)) 就會一直原地找 所以設一個參數
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

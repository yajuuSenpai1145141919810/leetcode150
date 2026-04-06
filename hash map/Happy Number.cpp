// 202. Happy Number
Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

class Solution {
public:
    bool isHappy(int n) {
        // 注意是set 檢查有沒有出現過
        unordered_set<int> see;

        // 注意直接用 !see.count(n) 就好
        while(n!=1&&!see.count(n)){  // 如果他不在裡面
            see.insert(n);
            n=ishappy(n);
        }
        return n==1;
    }

    int ishappy(int n){
        int sum=0;
        while(n>0){
            int d=n%10;  // n%=10; 不要太執著於這種寫法
            sum+=d*d; 
            n/=10; // 別忘了!
        }
        return sum;
    }
};

// 58. Length of Last Word
// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.

class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());

        int count=0;
        for(int x:s){
            if(x!=' '){
                count++;
            }else{
                // 這邊是重點  如果"moon  "轉完後變"  moon" 如果是第一個x==' '的話
                // count還沒開始算 所以這樣設
                if(count>0) return count;
            }
        }
        return count;
    }
};

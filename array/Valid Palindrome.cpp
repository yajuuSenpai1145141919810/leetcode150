// 125. Valid Palindrome

// 優化思路：不要開新的字串，直接在原字串 s 上使用 Two Pointers 
// 時間 空間複雜度都是O(n)
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int n=s.length();

        string result={};// 寫成""也可以
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){ // 直接套喔!
                result+=tolower(s[i]);
            }
        }

        string reversed=result;// 直接反轉字串就好
        reverse(reversed.begin(),reversed.end());
        return reversed==result;


    }
};

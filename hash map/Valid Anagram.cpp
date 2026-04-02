// 242. Valid Anagram
// Input: s = "anagram", t = "nagaram"
// Output: true

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();

        if(n!=m)return false;
        unordered_map<char,int> mapp;

        for(int x:s){
            mapp[x]++;
        }
        for(int y:t){
            // 這邊是重點因為長度固定了,如果會<=0代表不匹配
            if(mapp[y]>0){
                mapp[y]--;  
            }else{
                return false;
            }
        }
        return true;
    }
};
// 更快的解法
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        // 因為只有 26 個小寫字母，用陣列更快
        int count[26] = {0};
        
        for (char c : s) count[c - 'a']++;
        for (char c : t) {
            if (--count[c - 'a'] < 0) return false;
        }
        
        return true;
    }
};

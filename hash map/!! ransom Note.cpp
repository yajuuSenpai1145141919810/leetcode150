// 383. Ransom Note
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

// 關鍵! 用n--去看ransomNote是否已經沒有東西了 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 注意 因為這題是字母
        // 1. 直接開一個長度 26 的整數陣列，對應 a-z
        // int count[26] = {0}; 會比較好

        int n=ransomNote.length();
        int m=magazine.length();
        unordered_map<char ,int> mapp;


        // 以這題來說 其實先加上magazine再減ransomnote會比較好 不要透支
        for(int i=0;i<n;i++){
            mapp[ransomNote[i]]++;
        }

        for(int j=0;j<m;j++){
            if(mapp[magazine[j]]>0){
                mapp[magazine[j]]--;
                n--;
            }
            if(n==0){
                return true;
            }
        }
        // 執行 mapp['a']-- 讓它變成 0 時，Map 裡面的 Key 'a' 依然佔據一個位置
        // 所以不能用mapp.size()
        return n==0;
    }
};

// 205. Isomorphic Strings
// Input: s = "egg", t = "add"
// Output: true

class Solution {
public:
    bool isIsomorphic(string s, string t) {\

        // 陷阱s = "badc", t = "baba" s的b,d都會對應到t的b 不會錯喔!
        unordered_map <char,char> mapp;

        // 其實就反過來對照一遍
        unordered_map<char, char> mapp2;
        int n=s.length();
        
        // 原理就是上面說的可能會多對一 但是我雙向檢查 就可以變一對一
        for(int i=0;i<n;i++){
            // 如果在 Map 裡面『找到了』這個字
            if(mapp.find(s[i])!=mapp.end()){
                if(t[i]!=mapp[s[i]]){
                    return false;
                }
            }else{
                // 這邊是找不到喔! 所以要存進去
                mapp[s[i]]=t[i];
            }

            //把上面的複製下來 s,t互相改就好 
            if(mapp2.find(t[i])!=mapp2.end()){
                if(s[i]!=mapp2[t[i]]){
                    return false;
                }
            }else{
                mapp2[t[i]]=s[i];
            }            

        }
        return true;

    }
};

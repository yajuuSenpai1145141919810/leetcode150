class Solution {
public:
    int romanToInt(string s) {
      // 有對照的關係 用hash map
        unordered_map<char,int> map={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int result=0;
        int n=s.length();

        for(int i=0;i<n;i++){
            if(map[s[i]]<map[s[i+1]]&&i + 1 < n){
              // 對於前一位比較小的案例 就直接用減得即可!! 原本是a+(c-b)變成a-b+c 
                result-= map[s[i]];
            }else{
                result+=map[s[i]];    
            }
        }
        return result;
    }
};

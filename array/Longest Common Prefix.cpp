// 14. Longest Common Prefix/
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string result;// 注意 題目要的是string!!

        int n=strs.size(); //strs = ["flower","flow","flight"],strs.size()=3


        for(int i=0;i<(strs[0].size());i++){// 比f再l再o....

            char temp=strs[0][i];

            for(int j=1;j<n;j++){// 每筆資料的第i個位置
                // 「別人的子彈用完了嗎？」 (i == strs[j].size())
                // 「別人的子彈跟我一樣嗎？」 (strs[j][i] != temp)
                if(i>=strs[j].size() ||strs[j][i]!=temp){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];

    }
};

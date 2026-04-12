// 28. Find the Index of the First Occurrence in a String
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.

// 另一種寫法 有點像尺的比對 sliding window
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // 只需要遍歷到 haystack 剩下長度不足 needle 的地方即可
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i; // 遍歷完 needle，表示找到了
        }
        return -1;
    }
};
// 我的寫法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();   
        int fast=0;
        int slow=0;

        while(fast!=n&&slow!=m){
            if(haystack[fast]==needle[slow]){
                slow++;
                fast++; 
                
            }else{
                fast=fast-slow+1;// 要回退
                slow=0;
            }
        }
        if(slow==m){
            return fast-m;
        }
        return -1;

    }
};

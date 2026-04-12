// 28. Find the Index of the First Occurrence in a String
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
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

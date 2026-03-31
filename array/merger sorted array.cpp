// 88. Merge Sorted Array

// 標準寫法
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //因為後面是空的 所以從後面開始填
        int a=m-1;
        int b=n-1;
        int c=m+n-1;

        while(a>=0&&b>=0){　// 因為他要比較兩邊所以用＆＆
            if(nums1[a]>nums2[b]){
                nums1[c]=nums1[a];
                a--;
            }else{
                nums1[c]=nums2[b];
                b--;
            }
            c--;
        }
        while(b>=0){
            nums1[c]=nums2[b];
            c--;
            b--;
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // num1.size()=m+n;
        // num2.size()=n;
        nums1.erase(nums1.begin()+m,nums1.end());
        for(int x:nums2){
            nums1.push_back(x);
        }
        sort(nums1.begin(),nums1.end());
    }
};

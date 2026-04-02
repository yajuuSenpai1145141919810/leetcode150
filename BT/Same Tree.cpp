// 100. Same Tree
// Input: p = [1,2,3], q = [1,2,3]
// Output: true
// class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // 先處理空的，再處理值的，最後把左、右結果組合起
        if(p==nullptr&&q==nullptr) return true; //這邊是true

        // 不用寫if(p->left!=nullptr&&q->left!=nullptr) 因為遞迴一開始都會檢查
        // 上面檢查過兩個都0的 因此這邊必定是其中一個0或是兩個都有數值
        // p->val!=q->val 是如果前面兩個都有數字 就比他們 一不一樣
        if(p==nullptr||q==nullptr||p->val!=q->val) return false;

        // 因為我需要知道 左右兩邊 所以把上面的比較都寫好後 請信任他
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        
    }
};

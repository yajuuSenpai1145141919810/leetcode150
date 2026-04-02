// 104. Maximum Depth of Binary Tree
// Input: root = [3,9,20,null,null,15,7]
// Output: 3class Solution {
public:
    int maxDepth(TreeNode* root) {

        // 如果要「尋找特定目標」 或 「路徑探索」才會用return ,這邊要找深度所以正常加就好
        if(root==nullptr) return 0;
        // 不用寫 if(root->left!=nullptr){ 因為下個迴圈會自己處理掉
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        
        return  1+max(left,right);
    }
};

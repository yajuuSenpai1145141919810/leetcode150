// 226. Invert Binary Tree
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // root->left 和 root->right 都是指標（TreeNode*），
        // 所以 swap 會直接交換這兩個指標所指向的地址。

        if(root==nullptr) return nullptr;// 可以return nullptr!

        // 可以直接swap
        swap(root->left,root->right);

        // 如果你需要的只是叫它去動手做某事，就不需要接
        invertTree(root->left);
        invertTree(root->right);
        
        // 暫時先想成 題目回傳TreeNode 所以rerturn root
        return root;

    }
};

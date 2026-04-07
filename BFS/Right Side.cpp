// 199. Binary Tree Right Side View
// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]
// 時間複雜度：O(n)
// 空間複雜度: O(m)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                if(i==size-1){
                    result.push_back(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
        }   
        return result;       
    }
};

// 102. Binary Tree Level Order Traversal
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
          
            // 就是我先把第一層包好 放進去result 再抓第二層包好 
            vector<int> temp;// 每一層開一個籃子

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                // result[i].push_back(node->val); 千萬不能這樣寫 用vector<vector<int>> result;時不能直接存取第幾個
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            result.push_back(temp);
        }
        return result;
    }
};

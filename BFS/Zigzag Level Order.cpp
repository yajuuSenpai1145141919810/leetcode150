// 103. Binary Tree Zigzag Level Order Traversal
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., 
// from left to right, then right to left for the next level and alternate between).

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // zig zag是 第一層右到左 第二層做到右邊
        vector<vector<int>> result;

        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        
        // 本題技巧 設一個開關
        bool re=false;

        while(!q.empty()){
            vector<int> temp;// 把每一層包起來
            int size=q.size();

            for(int i=0;i<size;i++){

                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);

                // 這兩個順序絕對不能變喔!
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            //只要涉及「層」的操作，幾乎都在 for 迴圈外面做。
            // 如果re=true 才進去做反轉 變成右邊到左邊
            if(re)reverse(temp.begin(),temp.end());
            
            result.push_back(temp);
            re=!re;
        }
        return result;

    }
};

// 637. Average of Levels in Binary Tree
// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]

// time :o(n)
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) { // root 感覺只有一開始會用到
        // 流程: 建立queue,放入root,用while(!q.empty),抓size 設sum,用for去抓現在q裡面的內容 查看他有沒有孩子 有的畫放入queue
        vector<double> result;
        if(!root) return result;

        queue<TreeNode*> q;// 建立 queue  (可以放TreeNode*喔!)
        q.push(root); // root = [3,9,20,null,null,15,7] 裡面的3而已

        while(!q.empty()){ // 裡面有 3，開始跑
            int size=q.size(); // 這一層有多少個節點 此時=1只有一個3在裡面
            double sum=0;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front(); //設一個node 看前端的元素
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }

            result.push_back(sum/size);
        }

        return result;
    }
};

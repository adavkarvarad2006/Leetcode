/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;

        while(!q.empty()){
            int sz = q.size();

            if(level == depth - 1){
                while(sz--){
                    TreeNode *curr = q.front();
                    q.pop();

                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);

                    newLeft -> left = curr -> left;
                    newRight -> right = curr -> right;

                    curr -> left = newLeft;
                    curr -> right = newRight;
                }

                break;
            }

            while(sz--){
                TreeNode *curr = q.front();
                q.pop();

                if(curr -> left)
                    q.push(curr -> left);
                
                if(curr -> right)
                    q.push(curr -> right);
            }

            level++;
        }

        return root;
    }
};
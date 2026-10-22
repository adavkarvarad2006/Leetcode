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
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;

        stack<TreeNode*> st;
        st.push(root);

        TreeNode* prev = nullptr;

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            if(prev != nullptr){
                prev->left = nullptr;
                prev->right = curr;
            }

            //push right first so that left is processed first
            if(curr->right != nullptr)
                st.push(curr->right);

            if(curr->left != nullptr)
                st.push(curr->left);

            prev = curr;
        }
    }
};
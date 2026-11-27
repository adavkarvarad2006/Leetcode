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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;

        while(root != nullptr || !st.empty()){
            //Go to leftmost node
            while(root != nullptr){
                st.push(root);
                root = root -> left;
            }

            //visit the smallest node
            root = st.top();
            st.pop();

            k--;

            //if this is the kth node, return its val
            if(k == 0)
                return root -> val;

            //move to right subtree
            root = root -> right;
        }

        return -1;
    }
};
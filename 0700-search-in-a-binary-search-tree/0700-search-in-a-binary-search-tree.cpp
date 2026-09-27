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
void fun(TreeNode* root,int target,TreeNode* &ans)
{
    if(root == nullptr) return;
    if(root->val == target){
        ans = root;
        return;
    }
    if(root->val > target)
     fun(root->left,target,ans);
    else
     fun(root->right,target,ans);

    return;
}
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        fun(root,val,ans);

        return ans;
    }
};
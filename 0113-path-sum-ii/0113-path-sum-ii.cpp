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
void fun(TreeNode* root,int sum,int target,vector<int> &dairy,vector<vector<int>> &res)
{
    if(root == nullptr) return;
    sum = sum + root->val;
    dairy.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr){
       if(sum == target){
        res.push_back(dairy);
        dairy.pop_back();
        return;
       }
    }
    fun(root->left,sum,target,dairy,res);
    fun(root->right,sum,target,dairy,res);
    dairy.pop_back();
    return;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> dairy;
        vector<vector<int>> res;
        fun(root,0,targetSum,dairy,res);

        return res;
    }
};
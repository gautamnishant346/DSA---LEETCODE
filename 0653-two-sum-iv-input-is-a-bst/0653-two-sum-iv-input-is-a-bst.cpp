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
void fun(TreeNode* root,int k, vector<int> &tmp)
{
    if(root == nullptr) return;
    fun(root->left,k,tmp);
    tmp.push_back(root->val);
    fun(root->right,k,tmp);
    return;
}
    bool findTarget(TreeNode* root, int k) {
        vector<int> tmp;
        fun(root,k,tmp);
        int i = 0;
        int j = tmp.size()-1;
        while(i < j){
            int sum = tmp[i] + tmp[j];
            if(sum == k) return true;
            if(sum < k)  
              i++;
            else
              j--;
        }
        return false;
    }
};
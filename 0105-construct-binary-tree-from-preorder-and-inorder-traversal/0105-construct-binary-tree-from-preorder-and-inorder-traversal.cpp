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
    unordered_map<int,int> in;
    int idx = 0;
    TreeNode* fun(vector<int> &preorder,vector<int> &inorder,int low,int high)
    {
        if(low > high) return nullptr;
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        // inorder ma dada ko dhundo
        int id = in[node->val];
        node->left = fun(preorder,inorder,low,id-1);
        node->right = fun(preorder,inorder,id+1,high);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      for(int i=0; i<inorder.size(); i++)
        in[inorder[i]] = i;
      return fun(preorder,inorder,0,inorder.size()-1);    
    }
};
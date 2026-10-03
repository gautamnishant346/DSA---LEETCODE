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
int wrong = 0;
TreeNode* prev = nullptr;
TreeNode* g1first = nullptr;
TreeNode* g1second = nullptr;
TreeNode* g2first = nullptr;
TreeNode* g2second = nullptr;
void fun(TreeNode* root)
{
  if(root == nullptr) return;
  fun(root->left);
  if(prev == nullptr)
   prev = root;
  else{
    if(root->val <= prev->val){
        if(wrong == 0){
            g1first = prev;
            g1second = root;
            wrong++;
        }
        else{
            g2first = prev;
            g2second = root;
            wrong++;
        }
    }
    prev = root;
  }
  fun(root->right);
}
    void recoverTree(TreeNode* root) {
       fun(root);
       if(wrong == 1)
        swap(g1first->val,g1second->val);
       else
        swap(g1first->val,g2second->val);

       return; 
    }
};
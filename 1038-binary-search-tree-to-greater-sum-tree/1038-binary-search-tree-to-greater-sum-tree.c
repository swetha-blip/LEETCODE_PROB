/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int  sum=0;
 void convert(struct TreeNode*root)
 {
if(root==NULL)
        return;
    convert(root->right);
    sum+=root->val;
    root->val=sum;
    convert(root->left);

 }
struct TreeNode* bstToGst(struct TreeNode* root) {
    sum=0;
    convert(root);
    return root;
}
 
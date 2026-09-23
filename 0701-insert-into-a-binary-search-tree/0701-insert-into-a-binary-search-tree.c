/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root==NULL)
    {
        struct TreeNode* newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));

        newnode->val=val;
        newnode->left=NULL;
        newnode->right=NULL;

        return newnode;
    }
    if(val<root->val)
    {
        root->left=insertIntoBST(root->left,val);
    }
    if(val>root->val)
    {
        root->right=insertIntoBST(root->right,val);
    }
    return root;
}
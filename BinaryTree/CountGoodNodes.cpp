// LC 1448. Count Good Nodes in Binary Tree
// Issue was counting the leaf nodes towards max value when should be ignored. 
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
    int count = 0;
    int goodNodes(TreeNode* root) {
        int maxVal = 0;
        dfs(root, maxVal);
        return count;
    }

    void dfs(TreeNode* root, int& maxVal) {
        if(root == nullptr) return;
        
        if(root->val >= maxVal) {
            // maxVal = root->val;
            count++;
        }
	// If statement so maxVal does not include leaf nodes
        if(root->left == nullptr && root->right == nullptr) return;
        maxVal = max(maxVal, root->val);
        dfs(root->left, maxVal);
        dfs(root->right, maxVal);
    }
};

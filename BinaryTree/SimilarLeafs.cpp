// LC 872. Leaf-Similar Trees **DFS**

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
    vector<int> leafs1;
    vector<int> leafs2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        traverse(root1, leafs1);
        traverse(root2, leafs2);

        return leafs1 == leafs2;
    }

    void traverse(TreeNode* root, vector<int>& leafs) {
        if(root == nullptr) return;

        traverse(root->left, leafs);
        if(root->left == nullptr && root->right == nullptr) {
            leafs.push_back(root->val);
        }
        traverse(root->right, leafs);
    }
};

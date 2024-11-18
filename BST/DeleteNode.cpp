// LC 450. Delete Node in a BST

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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == nullptr) return root;

        // Search for node
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);

        // Find node and delete it
        else {
            // No children: Just delete node and return as null
            if(root->right == nullptr && root->left == nullptr) {
                delete root;
                return nullptr;
            }
            // One child: Left is empty, just delete node and replace with right
            else if(root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } // Right empty, delete node and replace with left
            else if(root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Two children: 1) Search for lowest node in right subtree. 
            //               2) Replace root val with lowest nodes val
            //               3) Delete lowest node from its original position in tree
            else {
                TreeNode* temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
    // Returns the minimum value of a tree given the root
    TreeNode* findMin(TreeNode* root) {
        while(root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
};

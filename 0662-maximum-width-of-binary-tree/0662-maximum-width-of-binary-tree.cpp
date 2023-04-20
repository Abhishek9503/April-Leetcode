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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   
            return 0;
        queue<pair<TreeNode*, ll>> que;
        que.push({root, 0});
        ll maxWidth = 0;
        
        while(!que.empty()) {
            int n = que.size();
            ll f = que.front().second;
            ll l = que.back().second;
            maxWidth = max(maxWidth, l-f+1);
            
            while(n--) {
                TreeNode* curr = que.front().first;
                ll d          = que.front().second;
                que.pop();
                if(curr->left) {
                    que.push({curr->left, 2*d+1});
                }
                if(curr->right) {
                    que.push({curr->right, 2*d+2});
                }
            }
        }
        return maxWidth;
    }
};
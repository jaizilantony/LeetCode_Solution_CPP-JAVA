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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == nullptr)
            return {};

        vector<vector<int>> ans;
        bool is_odd = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            deque<int> sim;  

            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(is_odd)
                {
                    sim.push_back(temp->val);
                }

                if(!is_odd)
                {
                    sim.push_front(temp->val);
                }

                if(temp->left)
                {
                    q.push(temp->left);
                }

                if(temp->right)
                {
                    q.push(temp->right);
                }
            }

            ans.push_back(vector<int>(sim.begin(), sim.end()));

            if(!is_odd)
            {
                is_odd = true;
            }
            else
            {
                is_odd = false;
            }
        }

        return ans;
    }
};
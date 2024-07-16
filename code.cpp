/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    string rootToStart, rootToEnd;
    void dfs(TreeNode* root, string& path, int start, int end) {
        if (root == nullptr)
            return;
        if (root->val == start)
            rootToStart = path;
        if (root->val == end)
            rootToEnd = path;

        path.push_back('L');
        dfs(root->left, path, start, end);
        path.pop_back();

        path.push_back('R');
        dfs(root->right, path, start, end);
        path.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path = "";
        dfs(root, path, startValue, destValue);
        int comm = 0, i = 0, j = 0;
        while (i < rootToStart.size() && j < rootToEnd.size()) {
            if (rootToStart[i] == rootToEnd[j]) {
                i++;
                j++;
                comm++;
            } else {
                break;
            }
        }
        rootToStart = rootToStart.substr(comm, rootToStart.size() - comm);
        rootToEnd = rootToEnd.substr(comm, rootToEnd.size() - comm);
        for (int i = 0; i < rootToStart.size(); i++) {
            rootToStart[i] = 'U';
        }
        return rootToStart + rootToEnd;
    }
};

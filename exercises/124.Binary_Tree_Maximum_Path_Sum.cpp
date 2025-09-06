#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }

private:
    int max_sum;

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_gain = max(0, dfs(node->left));
        int right_gain = max(0, dfs(node->right));
        int current_path_sum = node->val + left_gain + right_gain;
        max_sum = max(max_sum, current_path_sum);
        return node->val + max(left_gain, right_gain);
    }
};


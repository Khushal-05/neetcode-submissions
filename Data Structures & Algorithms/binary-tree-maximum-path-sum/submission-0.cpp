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
private:
    int globalMax;

    // Returns the maximum single-branch path sum extending down from `node`
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        // Clamp negative branch sums to 0
        int leftGain = std::max(0, maxGain(node->left));
        int rightGain = std::max(0, maxGain(node->right));

        // Path sum where `node` acts as the highest turnaround peak
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the best path sum seen so far
        globalMax = std::max(globalMax, currentPathSum);

        // Return the single branch gain to the parent
        return node->val + std::max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        globalMax = INT_MIN; // Base floor for trees with all negative nodes
        maxGain(root);
        return globalMax;
    }
};

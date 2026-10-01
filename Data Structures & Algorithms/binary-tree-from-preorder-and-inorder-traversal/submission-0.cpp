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
    TreeNode* build(const std::vector<int>& preorder, int preStart, int preEnd,
                    const std::vector<int>& inorder, int inStart, int inEnd,
                    const std::unordered_map<int, int>& inMap) {
        // Base Case: No elements left to construct
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // 1. Identify the root from preorder
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // 2. Locate root's position in inorder
        int rootIdx = inMap.at(rootVal);
        int leftSize = rootIdx - inStart;

        // 3. Recursively construct left and right subtrees
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           inorder, inStart, rootIdx - 1, inMap);

        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            inorder, rootIdx + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, inMap);
    }
};

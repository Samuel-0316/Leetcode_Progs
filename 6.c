/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = 0, rightHeight = 0;
    struct TreeNode *leftNode = root, *rightNode = root;
    
    while (leftNode != NULL) {
        leftHeight++;
        leftNode = leftNode->left;
    }
    
    while (rightNode != NULL) {
        rightHeight++;
        rightNode = rightNode->right;
    }
    
    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}
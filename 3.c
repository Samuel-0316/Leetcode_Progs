 void inorderTraversalHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;
    
    inorderTraversalHelper(root->left, result, index);
    result[(*index)++] = root->val;
    inorderTraversalHelper(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Count the number of nodes
    int count = 0;
    void countNodes(struct TreeNode* node) {
        if (node == NULL)
            return;
        countNodes(node->left);
        count++;
        countNodes(node->right);
    }
    countNodes(root);
    
    // Allocate memory for result array
    int* result = (int*)malloc(count * sizeof(int));
    *returnSize = count;
    
    // Perform inorder traversal
    int index = 0;
    inorderTraversalHelper(root, result, &index);
    
    return result;
}
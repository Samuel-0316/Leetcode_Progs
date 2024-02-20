int max(int a, int b) {
    return a > b ? a : b;
}

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int maxLen = 0;
    int dp[nums1Size + 1][nums2Size + 1];

    for (int i = 0; i <= nums1Size; i++) {
        for (int j = 0; j <= nums2Size; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return maxLen;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    // 不能malloc 可以改用靜態 #define MAX_N 10000 int dp[MAX_N + 1];
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    int offset = 1;
    for(int i = 1 ; i <= n ; i++){
        // offset * 2 == i 可改為 (i & (i - 1)) == 0
        if(offset * 2 == i){
            offset = i;
        }
        dp[i] = 1 + dp[i - offset];
    }
    * returnSize = n + 1;
    return dp;
}
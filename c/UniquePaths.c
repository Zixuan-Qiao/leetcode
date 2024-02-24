int uniquePaths(int m, int n) {

    if(m == 1 || n == 1) {
        return 1;
    }

    int dp[m][n];
    // for every position in the first colomn, there is only one path to reach it
    for(int i = 1; i < m; i++) {
        dp[i][0] = 1;
    }

    // for every position in the first row, there is only one path to reach it
    for(int j = 1; j < n; j++) {
        dp[0][j] = 1;
    }

    // based on the first colomn and first row, 
    // calculate the number of paths to reaching other positions
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}
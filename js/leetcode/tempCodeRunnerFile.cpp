or (int k = 0; k * candidates[i] <= j; k++)
            {
                dp[i + 1][j] = max(dp[i - 1][j], dp[i - 1][j - k * candidates[i]] + k * candidates[i]);
            }
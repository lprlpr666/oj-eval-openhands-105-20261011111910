#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // DP table: E[i][j] = expected days to eat j more apples when we have i apples
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0.0));
    
    // Base case: E[i][0] = 0 for all i (no more apples needed to eat)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0.0;
    }
    
    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j > i) continue; // Can't eat more apples than we have
            
            double sum = 0.0;
            int max_eat = min(i, j);
            
            // Sum over all possible amounts we can eat today
            for (int k = 1; k <= max_eat; k++) {
                sum += dp[i - k][j - k];
            }
            
            // Add the cases where we eat more than needed (k > j)
            for (int k = max_eat + 1; k <= i; k++) {
                sum += dp[i - k][0]; // We've already eaten all needed apples
            }
            
            // E[i][j] = 1 + (1/i) * sum
            dp[i][j] = 1.0 + sum / i;
        }
    }
    
    // Output result with 2 decimal places
    cout << fixed << setprecision(2) << dp[n][m] << endl;
    
    return 0;
}
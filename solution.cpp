#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // DP table: dp[i][j] = expected days to eat j apples when we have i apples total
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0.0));
    
    // Base case: dp[i][0] = 0 for all i (no apples to eat)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0.0;
    }
    
    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j > i) {
                dp[i][j] = 0.0; // Can't eat more apples than we have
                continue;
            }
            
            double expected = 0.0;
            // On each day, we eat k apples where k = 1, 2, ..., i with equal probability
            for (int k = 1; k <= i; k++) {
                if (k >= j) {
                    // We eat at least j apples, so we're done after this day
                    expected += 1.0;
                } else {
                    // We eat k apples, still need to eat j-k more from i-k apples
                    expected += 1.0 + dp[i - k][j - k];
                }
            }
            
            dp[i][j] = expected / i;
        }
    }
    
    // Output result with 2 decimal places
    cout << fixed << setprecision(2) << dp[n][m] << endl;
    
    return 0;
}
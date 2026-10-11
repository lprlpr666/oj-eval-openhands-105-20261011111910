#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<double>> memo;
vector<vector<bool>> computed;

double solve(int apples_left, int apples_to_eat) {
    if (apples_to_eat == 0) return 0.0;
    if (apples_left == 0) return 0.0;
    if (apples_to_eat > apples_left) return 0.0; // Can't eat more than we have
    
    if (computed[apples_left][apples_to_eat]) {
        return memo[apples_left][apples_to_eat];
    }
    
    double sum = 0.0;
    for (int k = 1; k <= apples_left; k++) {
        if (k <= apples_to_eat) {
            sum += solve(apples_left - k, apples_to_eat - k);
        } else {
            sum += 0.0; // We've eaten more than needed
        }
    }
    
    double result = 1.0 + sum / apples_left;
    memo[apples_left][apples_to_eat] = result;
    computed[apples_left][apples_to_eat] = true;
    
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    memo.resize(n + 1, vector<double>(m + 1, 0.0));
    computed.resize(n + 1, vector<bool>(m + 1, false));
    
    // Initialize base cases
    for (int i = 0; i <= n; i++) {
        memo[i][0] = 0.0;
        computed[i][0] = true;
    }
    
    double result = solve(n, m);
    
    // Output result with 2 decimal places
    cout << fixed << setprecision(2) << result << endl;
    
    return 0;
}
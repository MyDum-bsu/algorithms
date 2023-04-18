#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(3, INT64_MIN));

    dp[0][values[0] % 3] = values[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = INT64_MIN;
        dp[i][1] = INT64_MIN;
        dp[i][2] = INT64_MIN;

        if (i >= 2) {
            for (int j = 0; j < 3; j++) {
                if (dp[i - 2][j] != INT64_MIN) {
                    long long res = dp[i - 2][j] + values[i];
                    if (dp[i][(res % 3 + 3) % 3] == INT64_MIN || dp[i][(res % 3 + 3) % 3] < res) {
                        dp[i][(res % 3 + 3) % 3] = res;
                    }
                }
            }
        }

        if (i >= 5) {
            for (int j = 0; j < 3; j++) {
                if (dp[i - 5][j] != INT64_MIN) {
                    long long res = dp[i - 5][j] + values[i];
                    if (dp[i][(res % 3 + 3) % 3] == INT64_MIN || dp[i][(res % 3 + 3) % 3] < res) {
                        dp[i][(res % 3 + 3) % 3] = res;
                    }
                }
            }
        }
    }

    if (dp[n - 1][0] != INT64_MIN) {
        cout << dp[n - 1][0] << endl;
    } else {
        cout << -2023 << endl;
    }

    return 0;
}
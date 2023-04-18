#include <iostream>
#include <vector>

std::vector<int> make_minutes_for_tasks(int n);

std::vector<std::vector<int>> make_score(int n, int t);

int get_max_score(const std::vector<std::vector<int>> &score, const std::vector<int> &minutes);

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<int> minutes = make_minutes_for_tasks(n);
    std::vector<std::vector<int>> p = make_score(n, t);
    std::cout << get_max_score(p, minutes);
}

int get_max_score(const std::vector<std::vector<int>> &score, const std::vector<int> &minutes) {
    uint n = minutes.size();
    uint t = score.size();
    std::vector<std::vector<int>> dp(t, std::vector<int>(n));
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dp[t];
            }
        }
    }
    return dp[t][n];
}

std::vector<int> make_minutes_for_tasks(int n) {
    std::vector<int> minutes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> minutes[i];
    }
    return minutes;
}

std::vector<std::vector<int>> make_score(int n, int t) {
    std::vector<std::vector<int>> scores(t, std::vector<int>(n));
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> scores[i][j];
        }
    }
    return scores;
}
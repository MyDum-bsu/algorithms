#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Solution {
    std::vector<long double> &a;
    std::vector<long double> &b;
    int n, m;

    enum Difference {
        CheckTwo,
        AGreater,
        BGreater
    };

    std::pair<Difference, long double> FindWhatToDo() {
        long double diff = 1;
        int i = 0;
        int j = 0;
        while (true) {
            if (diff < 1 && i < n) {
                if (i == n - 1 && diff < 0.1 / m) {
                    return {BGreater, diff};
                }
                diff *= a[i];
                ++i;
            } else if (j < n) {
                if (j == n - 1 && diff > m) {
                    return {AGreater, diff};
                }
                diff /= b[j];
                ++j;
            } else if (diff >= 1 && i < n) {
                if (i == n - 1 && diff < 0.1 / m) {
                    return {BGreater, diff};
                }
                diff *= a[i];
                ++i;
            }
            if (i == j && i == n) {
                if (diff > m) {
                    return {AGreater, diff};
                }
                if (diff < 0.1 / m) {
                    return {BGreater, diff};
                }
                return {CheckTwo, diff};
            }
        }
    }

    long long Solve() {
        auto to_do = FindWhatToDo();
        auto type = to_do.first;
        long double diff = to_do.second;
        long long count = 0;
        if (type == BGreater) {
            return 0;
        }
        if (type == AGreater) {
            long long result = 0;
            for (int i = 0 ; i < n; i++) {
                result += m - a[i];
            }
            return result;
        }
        for (int i = 0; i < a.size(); ++i) {
            long double divided = a[i] / diff;
            long long value = ceill(divided);
            if (value <= m) {
                count += m - value + 1;
                if (a[i] >= value) {
                    count -= 1;
                }
            }
        }
        return count;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<long double> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    Solution solution{.a = a, .b = b, .n = n, .m = m};
    auto result = solution.Solve();
    std::cout << result;
    return 0;
}
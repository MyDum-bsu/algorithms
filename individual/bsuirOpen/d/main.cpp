#include <iostream>
#include <vector>
#include <numeric>

typedef long long int64;

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int64> vector(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vector[i];
    }

    std::vector<std::pair<int64, int64>> value_to_index(n);
    for (int i = 0; i < n; i++) {
        value_to_index[i] = {vector[i], i};
    }

    std::vector<std::vector<int64>> dp(n, std::vector<int64>(k, 0));

}

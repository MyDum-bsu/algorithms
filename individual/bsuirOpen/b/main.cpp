#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int p, q;
    cin >> p >> q;
    int x, y;
    cin >> x >> y;

    const int SECONDS_IN_MINUTE = 60;
    const int SECONDS_IN_HOUR = 3600;
    const int SECONDS_IN_12_HOURS = 12 * SECONDS_IN_HOUR;
    const double DEGREES_IN_RADIAN = 180.0 / M_PI;

    vector<pair<int, double>> angles;
    for (int t = 0; t < SECONDS_IN_12_HOURS; ++t) {
        double angle1 = (360.0 * t) / SECONDS_IN_HOUR;
        double angle2 = (360.0 * t) / SECONDS_IN_MINUTE;
        double angle3 = (360.0 * t) / SECONDS_IN_12_HOURS;
        double delta1 = abs(angle1 - angle2);
        double delta2 = abs(angle1 - angle3);
        double delta3 = abs(angle2 - angle3);
        angles.push_back({t, min({delta1, delta2, delta3})});
    }

    sort(angles.begin(), angles.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    vector<pair<int, int>> fractions;
    for (auto& [t, angle] : angles) {
        double degrees = angle * DEGREES_IN_RADIAN;
        int num = p * t;
        int den = q * SECONDS_IN_12_HOURS;
        int g = gcd(num, den);
        num /= g;
        den /= g;
        if (den > t) {
            continue;
        }
        if (abs(degrees - static_cast<double>(num) / den) < 1e-9) {
            fractions.push_back({num, den});
        }
    }

    sort(fractions.begin(), fractions.end(), [](auto& a, auto& b) {
        return a.first * b.second < b.first * a.second;
    });

    cout << fractions.size() << endl;
    for (auto& [num, den] : fractions) {
        cout << num << " " << den << endl;
    }

    return 0;
}

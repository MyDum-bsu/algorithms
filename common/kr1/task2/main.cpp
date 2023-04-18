#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0, j = n - 1;
    long long S = 0, ans = 0;
    vector<int> order(n);

    for (int k = 0; k < n; k++) {
        if (a[i] < a[j]) {
            ans = (ans + (20*S - 23*a[i]) % 1000000007 + 1000000007) % 1000000007;
            S += a[i];
            order[k] = i + 1;
            i++;
        } else {
            ans = (ans + (20*S - 23*a[j]) % 1000000007 + 1000000007) % 1000000007;
            S += a[j];
            order[k] = j + 1;
            j--;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << order[i] << " ";
    }

    return 0;
}

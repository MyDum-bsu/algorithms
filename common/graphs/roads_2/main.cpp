#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, q;
vector<vector<int>> g;
vector<bool> used;

bool check_connectivity() {
    int s = 1;
    queue<int> qq;
    qq.push(s);
    used[s] = true;
    while (!qq.empty()) {
        int v = qq.front();
        qq.pop();
        for (int to : g[v]) {
            if (!used[to]) {
                used[to] = true;
                qq.push(to);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    g.resize(q+1);
    used.resize(q+1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> ans(q, false);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int u = g[x][0], v = g[x][1];
        g[u].erase(find(g[u].begin(), g[u].end(), v));
        g[v].erase(find(g[v].begin(), g[v].end(), u));
        used.assign(n+1, false);
        ans[i] = check_connectivity();
    }

    for (bool b : ans) {
        cout << (b ? "coins" : "0");
    }
    cout << endl;

    return 0;
}

#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int check(vector<vector<int>>& a) {
    int n = (int)a.size();
    int val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int x = i; x < n; x++) {
                for (int y = j; y < n; y++) {
                    set<int> st;
                    for (int f = i; f <= x; f++) {
                        for (int s = j; s <= y; s++) {
                            st.insert(a[f][s]);
                        }
                    }
                    for (int cur = 0; cur <= n * n; cur++) {
                        if (!st.count(cur)) {
                            val += cur;
                            break;
                        }
                    }
                }
            }
        }
    }
    return val;
}

vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void even(vector<vector<int>>& a) {
    int n = (int)a.size();
    int val = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    q.push({n / 2 - 1, n / 2 - 1});
    q.push({n / 2 - 1, n / 2});
    q.push({n / 2, n / 2 - 1});
    q.push({n / 2, n / 2});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (vis[cur.first][cur.second]) continue;
        vis[cur.first][cur.second] = true;
        a[cur.first][cur.second] = val++;
        for (auto d : dirs) {
            if (ok(cur.first + d.first, cur.second + d.second, n, n)) {
                q.push({cur.first + d.first, cur.second + d.second});
            }
        }
    }
}

void odd(vector<vector<int>>& a) {
    int n = (int)a.size();
    int val = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    q.push({n / 2, n / 2});
    q.push({n / 2 + 1, n / 2});
    q.push({n / 2, n / 2 + 1});
    q.push({n / 2 + 1, n / 2 + 1});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (vis[cur.first][cur.second]) continue;
        vis[cur.first][cur.second] = true;
        a[cur.first][cur.second] = val++;
        for (auto d : dirs) {
            if (ok(cur.first + d.first, cur.second + d.second, n, n)) {
                q.push({cur.first + d.first, cur.second + d.second});
            }
        }
    }
}

// void other(vector<vector<int>>& a) {
//     int n = (int)a.size();
//     a[0][0] = 0;
//     int val = 1;
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             a[j][i] = val++;
//         }
//         a[i][i] = val++;
//         for (int j = i - 1; j >= 0; j--) {
//             a[i][j] = val++;
//         }
//     }
// }

vector<vector<int>> dir2 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void spiral(vector<vector<int>>& a) {
    int n = (int)a.size();
    pair<int, int> centre;
    centre = {n / 2, n / 2};
    if (n % 2 == 0) centre = {n / 2 - 1, n / 2 - 1};
    int nxt = 0;
    int prev = 3;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    a[centre.first][centre.second] = 0;
    vis[centre.first][centre.second] = true;
    for (int cur = 1; cur < n * n; cur++) {
        // while (!ok(centre.first + dir2[nxt][0], centre.second + dir2[nxt][1],
        // n,
        //            n)) {
        //     nxt++;
        // }
        if (!vis[centre.first + dir2[nxt][0]][centre.second + dir2[nxt][1]]) {
            centre.first += dir2[nxt][0];
            centre.second += dir2[nxt][1];
            a[centre.first][centre.second] = cur;
            vis[centre.first][centre.second] = cur;
            prev = nxt;
            nxt = (nxt + 1) % 4;
        } else {
            centre.first += dir2[prev][0];
            centre.second += dir2[prev][1];
            a[centre.first][centre.second] = cur;
            vis[centre.first][centre.second] = cur;
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> a(n, vector<int>(n));
    spiral(a);
    vector<vector<int>> c = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    vector<vector<int>> b = {{8, 4, 5}, {6, 0, 1}, {7, 2, 3}};
    vector<vector<int>> tmp = {{6, 7, 8}, {5, 0, 1}, {4, 3, 2}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

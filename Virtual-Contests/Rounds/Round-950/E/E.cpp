#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool custom_comparator(vector<int>& a, vector<int>& b) {
    return a.front() < b.front();
}

void transpose(vector<vector<int>>& a) {
    int n = (int)a.size(), m = (int)a[0].size();
    vector<vector<int>> tmp(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp[j][i] = a[i][j];
        }
    }
    a = tmp;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &b[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) swap(a[i], a[0]);
            if (b[i][j] == 1) swap(b[i], b[0]);
        }
    }
    transpose(a);
    transpose(b);
    sort(a.begin(), a.end(), custom_comparator);
    sort(b.begin(), b.end(), custom_comparator);
    transpose(a);
    transpose(b);
    sort(a.begin(), a.end(), custom_comparator);
    sort(b.begin(), b.end(), custom_comparator);
    bool ans = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                ans = false;
            }
        }
    }
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

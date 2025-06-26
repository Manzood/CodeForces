#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if (a[i] > b[i]) {
            ans.push_back({3, i});
            swap(a[i], b[i]);
        }
    }

    vector<int> temp = a;
    map<int, int> pos;
    for (int i = 0; i < n; i++) pos[a[i]] = i;
    sort(temp.begin(), temp.end());

    for (int i = 0; i < n; i++) {
        int cur = pos[temp[i]];
        for (int j = cur - 1; j >= i; j--) {
            ans.push_back({1, j});
            pos[a[j]] = j + 1;
            pos[a[j + 1]] = j;
            swap(a[j], a[j + 1]);
        }
    }

    temp = b;
    pos.clear();
    for (int i = 0; i < n; i++) pos[b[i]] = i;
    sort(temp.begin(), temp.end());

    for (int i = 0; i < n; i++) {
        int cur = pos[temp[i]];
        for (int j = cur - 1; j >= i; j--) {
            ans.push_back({2, j});
            pos[b[j]] = j + 1;
            pos[b[j + 1]] = j;
            swap(b[j], b[j + 1]);
        }
    }

    printf("%lld\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld %lld\n", ans[i].first, ans[i].second + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

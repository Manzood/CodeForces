#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    set<int> s;
    map<int, int> ind;
    vector<int> getpower(21, 1);
    int temp = 3;
    for (int i = 1; i <= 20; i++) {
        getpower[i] = temp;
        temp *= 3;
    }
    // convert to ternary and back
    vector<vector<int>> c(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < k; j++) {
            scanf("%lld", &c[i][j]);
            num += c[i][j] * getpower[k - j];
        }
        s.insert(num);
        ind[num] = i;
    }
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // check if the third value exists
            int num = 0;
            for (int x = 0; x < k; x++) {
                if (c[i][x] == c[j][x]) {
                    num += c[i][x] * getpower[k - x];
                } else {
                    int val = 0;
                    while (val == c[i][x] || val == c[j][x]) val++;
                    num += val * getpower[k - x];
                }
            }
            if (s.count(num)) {
                if (ind[num] > j) {
                    cnt[i]++;
                    cnt[j]++;
                    cnt[ind[num]]++;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

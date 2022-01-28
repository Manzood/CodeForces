#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> b = a;
    sort(b.begin(), b.end());
    int x = 1;
    int y = n;
    for (int i = 0; i + k + (n - k + 1) / 2 - 1 < n; i++) {
        int ind = i + k + (n - k + 1) / 2 - 1;
        // this could be better written as
        // ind = i + (n + k - 1) / 2
        // debug (a, i, ind);
        int curx = b[i];
        int cury = b[ind];
        if (cury - curx < y - x) {
            y = cury;
            x = curx;
        }
    }
    printf("%lld %lld\n", x, y);
    // debug (x, y);
    int p = 0;
    int cnt = 0;
    int len = 0;
    vector <vector <int>> partitions;
    for (int i = 0; i < n; i++) {
        len++;
        if (a[i] >= x && a[i] <= y) cnt++;
        if (cnt > len / 2) {
            p++;
            partitions.push_back ({i - len + 1, i});
            cnt = 0;
            len = 0;
        }
    }
    for (int i = 0; i < k - 1; i++) {
        printf("%lld %lld\n", partitions[i][0] + 1, partitions[i][1] + 1);
    }
    printf("%lld %lld\n", partitions[k-1][0] + 1, n);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}

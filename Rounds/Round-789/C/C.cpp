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
    vector <int> p(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &p[i]);
    }
    vector <int> smaller(n, 0);
    vector <vector <int>> bigger(n, vector <int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                smaller[i]++;
            }
        }
        for (int j = i - 1; j >= 0; j--) {
            bigger[i][j] = bigger[i][j+1];
            if (p[j] > p[i]) bigger[i][j]++;
        }
    }
    int ans = 0;
    for (int a = 0; a < n - 3; a++) {
        int val = smaller[a + 1];
        for (int c = a + 2; c < n - 1; c++) {
            val -= bigger[c][a + 1];
            if (p[c] > p[a]) {
                ans += val;
            }
            val += smaller[c];
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

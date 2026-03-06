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
    if (k == n * n - 1) {
        printf("NO\n");
        return;
    }

    vector<string> a(n, string(n, 'D'));

    if (k < n * n) {
        int cnt = 2, target = n * n - k;
        a[1][0] = 'U';
        while (cnt < n && cnt < target) {
            a[cnt++][0] = 'U';
        }
        target -= cnt;
        int col = 1, row = 0;
        while (target > 0) {
            if (row == n) {
                col++;
                row = 0;
            }
            a[row++][col] = 'L';
            target--;
        }
    }

    printf("YES\n");
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

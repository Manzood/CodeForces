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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    string out;
    for (int i = 0; i < n / 2; i++) {
        if (i & 1) {
            if (a[i] < a[n - i - 1]) {
                out += "LR";
            } else {
                out += "RL";
            }
        } else {
            if (a[i] < a[n - i - 1]) {
                out += "RL";
            } else {
                out += "LR";
            }
        }
    }
    if (n & 1) out += 'L';

    cout << out << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

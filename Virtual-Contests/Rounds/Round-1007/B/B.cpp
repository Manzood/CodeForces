#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

set<int> squares;
bool isPerfectSq(int n) {
    if (squares.count(n)) return true;
    return false;
}

void precompute() {
    int val = 1;
    while (val < (int)1e6) {
        squares.insert(val * val);
        val++;
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    if (isPerfectSq(n * (n + 1) / 2)) {
        printf("-1\n");
        return;
    }
    vector<int> a = {2, 1};
    for (int i = 2; i < n; i++) {
        a.push_back(i + 1);
    }

    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (isPerfectSq(s)) {
            assert(i != n - 1);
            s -= a[i];
            swap(a[i], a[i + 1]);
            s += a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    precompute();

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    vector<int> ap(n + 1, 0), bp(n + 1, 0);
    vector<int> aloc(n + 1, 0), bloc(n + 1, 0);
    int same_count = 0;
    for (int i = 0; i < n; i++) {
        ap[a[i]] = b[i];
        bp[b[i]] = a[i];
        aloc[a[i]] = i;
        bloc[b[i]] = i;
        if (a[i] == b[i]) same_count++;
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (ap[i] != bp[i]) possible = false;
    }
    if (same_count > 1)
        possible = false;
    else if (n % 2 == 0 && same_count == 1)
        possible = false;
    if (!possible) {
        printf("-1\n");
        return;
    }

    int ans = 0;
    vector<pair<int, int>> out;
    if (n & 1) {
        int mid = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] == a[i]) {
                mid = i;
            }
        }
        assert(mid != -1);
        if (mid != n / 2) {
            ans++;
            out.push_back({mid, n / 2});
            swap(aloc[a[mid]], aloc[a[n / 2]]);
            swap(bloc[b[mid]], bloc[b[n / 2]]);
            swap(a[mid], a[n / 2]);
            swap(b[mid], b[n / 2]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        int ind = bloc[ap[b[i]]];
        if (ind != n - i - 1) {
            ans++;
            out.push_back({ind, n - i - 1});
            swap(aloc[a[ind]], aloc[a[n - i - 1]]);
            swap(bloc[b[ind]], bloc[b[n - i - 1]]);
            swap(a[ind], a[n - i - 1]);
            swap(b[ind], b[n - i - 1]);
        }
    }
    printf("%lld\n", (int)out.size());
    for (int i = 0; i < (int)out.size(); i++) {
        printf("%lld %lld\n", out[i].first + 1, out[i].second + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

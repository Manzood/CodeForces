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
    vector<int> even, odd, pos(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
        if (i & 1)
            odd.push_back(a[i]);
        else
            even.push_back(a[i]);
        pos[a[i]] = i;
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    for (int i = 0; i < n - 3; i++) {
        int val = (i & 1) ? odd[i / 2] : even[i / 2];
        int ind = pos[val];
        if (ind > i) {
            if (ind == n - 1) {
                swap(a[n - 3], a[n - 1]);
                swap(a[n - 4], a[n - 2]);
                ind = n - 3;
                pos[a[n - 2]] = n - 2;
                pos[a[n - 4]] = n - 4;
                pos[a[n - 3]] = n - 3;
                pos[a[n - 1]] = n - 1;
            }
            swap(a[i], a[ind]);
            swap(a[i + 1], a[ind + 1]);
            pos[a[i]] = i;
            pos[a[i + 1]] = i + 1;
            pos[a[ind]] = ind;
            pos[a[ind + 1]] = ind + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i] + 1);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

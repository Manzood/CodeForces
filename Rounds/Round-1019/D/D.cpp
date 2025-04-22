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
    int high = n, low = 1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int run = 1;
    vector<int> out(n);
    while (high > low) {
        int prev = -1;
        vector<int> ind;
        if (run & 1) {
            for (int i = 0; i < n; i++) {
                if (a[i] == run) {
                    ind.push_back(i);
                    out[i] = high--;
                } else if (a[i] > run || a[i] == -1) {
                    prev = i;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (a[i] == run) {
                    ind.push_back(i);
                    out[i] = low++;
                } else if (a[i] > run || a[i] == -1) {
                    prev = i;
                }
            }
        }
        if ((int)ind.size() > 1) {
            if (ind.back() > prev && ind[(int)ind.size() - 2] > prev) {
                vector<int> val;
                for (auto x : ind)
                    if (x > prev) val.push_back(out[x]);
                reverse(val.begin(), val.end());
                int cur = 0;
                for (auto x : ind)
                    if (x > prev) out[x] = val[cur++];
            }
        }
        run++;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) out[i] = low;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", out[i]);
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

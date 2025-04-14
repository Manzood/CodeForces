#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n = 0, dir = 1;
    int q;
    scanf("%lld", &q);
    int cur = 0, rev = 0, sum = 0;
    deque<int> a;
    for (int i = 0; i < q; i++) {
        int op;
        scanf("%lld", &op);
        if (op == 1) {
            int val = 0;
            if (dir == 1) {
                val = a.back();
                a.push_front(val);
                a.pop_back();
            } else {
                val = a.front();
                a.push_back(val);
                a.pop_front();
            }
            int diff = sum - val - (n - 1) * val;
            cur += diff;
            rev -= diff;
        } else if (op == 2) {
            swap(cur, rev);
            dir = !dir;
        } else {
            n++;
            int val;
            scanf("%lld", &val);
            if (dir == 1)
                a.push_back(val);
            else
                a.push_front(val);
            cur += val * n;
            sum += val;
            rev += sum;
        }
        printf("%lld\n", cur);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int cyclicsub (int val, int sub, int n) {
    val -= sub;
    if (val < 0) {
        val += n;
    }
    return val;
}

// int cyclicdiff (int v1, int v2, int n) {
//     // v1 - v2
//     if (v1 >= v2) return v1 - v2;
//     else return v1 - v2 + n;
// }

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    vector <int> pos(n + 1, -1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pos[a[i]] = i;
    }
    int expected = n - 1;
    vector <int> answer;
    vector <bool> marked(n, false);
    for (int i = n; i > 0; i--) {
        marked[pos[i]] = true;
        if (pos[i] != expected) {
            // debug (pos[i], expected);
            int ind = (expected + 1) % n;
            int shift = 1;
            for (int j = 0; j < n; j++) {
                if (a[ind] == i) {
                    break;
                }
                // if (i == 4) {
                //     debug(ind, shift, marked[ind]);
                // }
                if (!marked[ind]) {
                    shift++;
                }
                ind++;
                ind %= n;
            }
            if (i == 1) shift = 0;
            answer.push_back(shift);
        } else {
            answer.push_back(0);
        }
        expected = cyclicsub(pos[i], 1, n);
        while (i > 1 && marked[expected]) {
            expected = cyclicsub(expected, 1, n);
        }
    }
    reverse(answer.begin(), answer.end());
    for (int i = 0; i < n; i++) {
        printf("%lld%c", answer[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int rand (int a, int b) {
    return (a + (rand() % (b - a + 1)));
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    iota(a.begin(), a.end(), 1);
    set <vector <int>> allowed;
    do {
        vector <int> c(n, 0);
        vector <int> temp = a;
        for (int i = 0; i < n; i++) {
            temp.push_back(a[i]);
        }
        int ind = 0;
        for (int i = n; i > 0; i--) {
            int max_so_far = 0;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (temp[i + j] > max_so_far) {
                    cnt++;
                    max_so_far = temp[i + j];
                }
            }
            c[ind++] = cnt;
        }
        allowed.insert(c);
        // debug (a, c);
        // for (int i = 0; i < n; i++) {
        //     printf("%lld%c", c[i], " \n"[i == n - 1]);
        // }
    } while (next_permutation(a.begin(), a.end()));
    int t = 100;
    printf("%lld\n", t);
    while (t--) {
        vector <int> temp(n, 0);
        do {
            for (int i = 0; i < n; i++) {
                temp[i] = rand(1, n);
            }
        } while (allowed.count(temp));
        for (int i = 0; i < n; i++) {
            printf("%lld ", temp[i]);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

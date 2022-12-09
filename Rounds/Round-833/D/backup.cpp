#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b, d;
    scanf("%lld%lld%lld", &a, &b, &d);
    vector<int> mask(3, 0);
    // mask[0] -> off bits for a and on for b
    // mask[1] -> off bits for b and on for a
    // mask[2] -> off bits for both
    for (int i = 0; i <= 30; i++) {
        int val = 1LL << i;
        if (!(val & a) && !(val & b)) {
            mask[2] += val;
        } else if ((val & a) && !(val & b)) {
            mask[1] += val;
        } else if (!(val & a) && (val & b)) {
            mask[0] += val;
        }
    }
    // generate possible additions modulo D
    vector<vector<int>> possible(3);
    vector<vector<int>> ind(3);
    for (int i = 0; i <= 30; i++) {
        int val = (1LL << i);
        if (mask[2] & val) {
            possible[2].push_back(val % d);
            ind[2].push_back(i);
        }
        if (mask[1] & val) {
            possible[1].push_back((val + b) % d);
            ind[1].push_back(i);
        }
        if (mask[0] & val) {
            possible[0].push_back((val + a) % d);
            ind[0].push_back(i);
        }
    }
    // create all sums possible
    vector<set<int>> sums(3);
    vector<map<int, int>> val(3);
    for (int j = 0; j < 3; j++) {
        if ((int)possible[j].size() > 0) {
            sums[j].insert(possible[j][0]);
            val[j][(1LL << ind[j][0])] = (1LL << ind[j][0]);
        }
        for (int i = 1; i < (int)possible[j].size(); i++) {
            set<int> cpy1 = sums[j];
            map<int, int> cpy2 = val[j];
            for (auto x : cpy1) {
                int tmp = (possible[j][i] + x) % d;
                sums[j].insert(tmp);
                int cur = (1LL << ind[j][i]);
                assert((cur & cpy2[x]) == 0);
                cur += cpy2[x];
                val[j][tmp] = cur;
            }
        }
    }
    // found the possible sums you can create
    bool found = false;
    int ans = -1;
    for (auto i : sums[0]) {
        if (found) break;
        for (auto j : sums[1]) {
            if (found) break;
            for (auto k : sums[2]) {
                if (((((i) % d) + k) % d) == 0 && (((j) % d) + k) % d == 0) {
                    ans = val[0][i] + val[1][j] + val[2][k];
                    found = true;
                    break;
                }
            }
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

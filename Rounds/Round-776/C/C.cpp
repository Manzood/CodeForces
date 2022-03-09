#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <vector <int>> a(m, vector <int> (3));
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &a[i][1], &a[i][0]);
        a[i][2] = i;
    }
    sort (a.begin(), a.end());
    vector <vector <int>> second;
    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        second.push_back({a[i][1], a[i][0], a[i][2]});
        sum += a[i][0];
    }
    sort (second.begin(), second.end());
    vector <vector <int>> answer;
    int endptr = 2 * n - 1;
    for (int i = 0; i < n; i++) {
        answer.push_back ({second[i][2], second[endptr--][2]});
    }
    printf("%lld\n", sum);
    for (int i = 0; i < n; i++) {
        printf("%lld %lld\n", answer[i][0] + 1, answer[i][1] + 1);
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

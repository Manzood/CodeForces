#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int rand (int a, int b) {
    return a + (rand() % (b - a + 1));
}

int get_cost (vector <int>& a, vector <int>& b) {
    int cost = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cost += (a[i] + a[j]) * (a[i] + a[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cost += (b[i] + b[j]) * (b[i] + b[j]);
        }
    }
    return cost;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <int> a(n), b(n);
    int suma = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        suma += a[i];
    }
    int sumb = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        sumb += b[i];
    }
    for (int i = 0; i < n; i++) {
        if (suma - a[i] > sumb - b[i]) {
            if (a[i] > b[i]) {
                suma -= a[i];
                sumb -= b[i];
                swap (a[i], b[i]);
                suma += a[i];
                sumb += b[i];
            }
        } else if (sumb - b[i] > suma - a[i]) {
            if (b[i] > a[i]) {
                suma -= a[i];
                sumb -= b[i];
                swap (a[i], b[i]);
                suma += a[i];
                sumb += b[i];
            }
        }
    }
    debug (a, b);
    int cost = get_cost (a, b);
    printf("%lld\n", cost);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

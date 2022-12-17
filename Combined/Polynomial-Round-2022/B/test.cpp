#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define le length

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int a[m + 10];
        for (int i = 1; i <= m; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + m);
        if (k > m)
            cout << "NO\n";
        else if (k == m) {
            if (n % k == 0) {
                if (a[1] == a[m]) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                int q = n % k;
                int x = n / k;
                if (a[1] == a[m - q] && a[1] == x && a[m - q + 1] == a[m] &&
                    a[m] == x + 1) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        } else {
            if (n % k == 0) {
                if (a[m] > n / k) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                }
            } else {
                if (a[m] <= n / k + 1 && a[m - n % k] <= n / k) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
}

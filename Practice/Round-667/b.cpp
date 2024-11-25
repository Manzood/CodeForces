#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        if (max(a-n, x) > max(b-n, y)) {
            swap(a, b);
            swap(x, y);
        }
        int m = min(n, a-x);
        a -= m;
        n -= m;
        m = min(n, b-y);
        b -= m;
        n -= m;
        long long ans = (long long) a * b;
        cout << ans << '\n' ;
    }
}
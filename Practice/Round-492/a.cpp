#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int INF = 1e9;

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = n/100;
        n %= 100;
        ans += n/20;
        n %= 20;
        ans += n/10;
        n %= 10;
        ans += n/5;
        n %= 5;
        ans += n;
        printf("%d\n", ans);
    }
}
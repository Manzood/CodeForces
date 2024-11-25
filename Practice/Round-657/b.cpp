#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r, m;
        scanf("%lld%lld%lld", &l, &r, &m);
        long long a;
        for (a=l; a<=r; a++) {
            if (m%a <= r-l+1 && m/a > 0 && r-(m%a) >= l) {
                printf("%lld %lld %lld\n", a, r, r-(m%a));
                break;
            }
            else if ((a*(m/a)+a-m) <= r-l+1) {
                if (r-(a*(m/a)+a-m) >= l) {
                    printf("%lld %lld %lld\n", a, r-(a*(m/a)+a-m), r);
                    break;
                }
            }
        }
    }   
}
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int a, b;
        scanf("%d%d\n", &a, &b);
        int temp = abs(a-b)%10;
        if (temp > 0) temp = 1;
        printf("%d\n", abs(a-b)/10+temp);
    }
}
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int rand (int a, int b) {
    return rand()%(b-a+1) + a;
}

int main() {
    int t;
    t = rand(1, 10);
    cout << t << endl;
    for (int i = 0; i < t; i++) {
        int n = rand(1, 10);
        int k = rand(1, max(n-1, 1));
        int z = rand(0, min(5, k));
        printf("%d %d %d\n", n, k, z);
        for (int j = 0; j < n; j++) {
            int x = rand(1, 100);
            cout << x << " ";
        }
        cout << endl;
    }
}

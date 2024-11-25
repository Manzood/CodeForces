#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		long long a, b, n, m;
		scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
		bool possible = true;
		if (m > min(a, b)) possible=false;
		else {
			if (a < b) 
				a -= m;	
			else 
				b -= m;
			if (a + b < n) 
				possible = false;
		}
		if (possible) printf("YES\n");
		else printf("NO\n");
	}
}
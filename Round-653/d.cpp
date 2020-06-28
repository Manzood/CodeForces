#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t; cin>>t;
	while (t--) {
		long long n, k;
		scanf("%lld %lld",&n,&k);
		map <int, int> a;
		long long x=0;
		for (int i=0;i<n;i++) {
			long long temp;
			scanf("%lld",&temp);
			if (temp%k>0) {
				temp=k-temp%k;
				a[temp]++;
				long long val=temp+((long long)k*(a[temp]-1));
				x=max(val+1,x);
			}
		}
		if (x>0)
			printf("%lld\n",x);
		else 
			printf("0\n");
	}	
}

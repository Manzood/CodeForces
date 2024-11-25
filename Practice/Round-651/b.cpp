#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		debug(n);
		vector <int> a(2*n);
		int oddcount=0,evencount=0;
		for (int i=0;i<2*n;i++) {
			scanf("%d",&a[i]);
			if (n%2) evencount++;
			else oddcount++;
		}
		int removed=0;
		vector <int> ans;
		int temp=-1;
		int cnt=0;
		int even=0;
		for (int i=0;i<2*n;i++) {
			if (a[i]%2==1) {
				if (removed==0)
					removed++;
				else if (removed==1 && oddcount%2==0)
					removed++;
				else {
					debug(a[i]);
					if ((temp+a[i])%2==0 && temp!=-1) {
						printf("%d %d\n",temp,a[i]);
						temp=-1;
					}
					else 
						temp=a[i];
				}
			}
			else {
				if (removed< 2 && oddcount%2==1) 
					removed++;
				if (cnt==1) {
					printf("%d %d\n",even,a[i]);
					even=0;
					cnt=0;
				}
				else {
					cnt++;
					even=a[i];
				}
			}
		}
	}
}
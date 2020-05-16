#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int a,b,c,d;
	scanf("%d %d %d %d\n",&a,&b,&c,&d);
	long long ans=0;
	for (int z=c;z<=b+c && z<=d;z++) {
		int y=c;
		int start=z-c+1;
		ans+=pow(b-a+1,min(c-b+1,(a-start+1)));
		debug(ans);
		y-=(a-start+1);
		if (y<b)
			continue;
		int x=a+1;
		while (y>b) {
			ans+=b-x;
			x++;
			y--;
		}
	}
	printf("%lld\n",ans);
}

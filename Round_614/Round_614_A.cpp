#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		long long n,s,k;
		scanf("%lld %lld %lld", &n, &s, &k);
		s--;
		vector <int> a(n);
		for (long long i=0;i<n;i++)
			a[i]=1;
		long long b;
		while (k--)
		{
			scanf ("%lld",&b);
			a[b-1]=0;
		}
		long long ans;
		ans=n;
		for (long long i=0;i<n;i++)
		{
			if (a[i]==1)
			{
				if (abs(i-s)<ans)
				{
					ans=abs(i-s);
				}
			}
		}
		if (ans==n)
			printf("0\n");
		else
			printf("%lld\n",ans);
	}
}	
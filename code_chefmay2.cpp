#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
double startTime;
double getCurrentTime()
{
	return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}

lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x)%MOD;
		x=(x*x)%MOD;
	}
	return res;
}
lli inver(lli num)
{
	return pwr(num,MOD-2);
}
lli findncr(lli n,lli r)
{
	r=min(r,n-r);
	if(n==0||n==1||r==0)
		return 1;
	lli numer=1;
	for(lli i=n;i>=n-r+1;i--)
		numer=(numer*i)%MOD;
	lli den=1;
	for(lli i=2;i<=r;i++)
		den=(den*i)%MOD;
	den=inver(den);
	lli res=(numer*den)%MOD;
	return res;
}
lli gcd(lli a,lli b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>vec(n+1,0);
		fr2(i,n)
		cin>>vec[i+1];
		vector<int> diff(n+1,0);
		diff[1]=vec[1];
		for(int i=2;i<=n;i++)
			diff[i]=vec[i]-vec[i-1];
		for(int i=1;i<=n;i++)
		{
			if(diff[i]>2)
				diff[i]=-1;
			else
				diff[i]=1;
		}
		int ans1=INT_MIN;
		int ans2=INT_MAX;
		int c=0;
		// for(int i=2;i<=n;i++)
		// 	cout<<diff[i]<<" ";

		for(int i=2;i<=n;i++)
		{
			if(diff[i]==1)
			{
				c++;
			
			//cout<<c<<endl;
		}
			else
			{

				ans1=max(ans1,c);
				ans2=min(ans2,c);
				//cout<<ans1<<" "<<ans2<<endl;
				c=0;
			}

		}
		ans1=max(ans1,c);
		ans2=min(ans2,c);
		cout<<ans2+1<<" "<<ans1+1<<endl;

		}
	}
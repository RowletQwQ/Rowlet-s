#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
ll n,k,num[100005],ans,test,maxn;
bool cmp(ll x,ll y){
	return x<y;
}
ll max(ll x,ll y){
	if(x>y)return x;
	return y;
}
inline void readi(ll &x){
	char c;
	bool is=false;
	for(c=getc(stdin);c<'0'||c>'9';c=getc(stdin))if(c=='-')is=true;
	for(x=0;c<='9'&&c>='0';c=getc(stdin))x=(x<<1)+(x<<3)+c-'0';
	if(is)x=-x;
}
ll solve(ll l,ll r){
	if(r-l==1)return l;
 	ll tl=0,tr=0,mid=(l+r)>>1;
 	for(int i=1;i<=n;i++){
 		tl+=num[i]/mid;
 		tr+=num[i]/r;
	 }
	if(tr>=k){
		return r;
	}else if(tl<k){
		return solve(l,mid);
	}else{
		return solve(mid,r);
	}
	return 0;	
}
int main(int argc, char** argv) {
	readi(n);readi(k);
	for(int i=1;i<=n;i++){
		readi(num[i]);
		test+=num[i];
		maxn=max(maxn,num[i]);
	}
	if(test<k){
		printf("%lld",ans);
	}else if(test==k){
		printf("1");
	}else{
		//sort(num+1,num+1+n,cmp);
		ans=solve(1,maxn);
		printf("%lld",ans);
	}
	return 0;
}

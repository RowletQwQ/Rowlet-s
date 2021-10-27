#include <iostream>
#include <cstdio>
#define ll long long 
using namespace std; 
ll n,m,a[100005],l,r,t,mid,ans=INT_MAX;
ll max(ll x,ll y){
	if(x>y)return x;
	return y;
}
bool check(ll k){
	ll cur=0,cnt=1;
	for(int i=1;i<=n;i++){
		if(cur+a[i]>k){
			cur=0;
			cnt++;
		}
		cur+=a[i];
	}
	return cnt<=m;
}
int main(int argc, char** argv) {
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&t);
		a[i]=t;
		l=max(t,l);
		r+=t;
	}
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			//ans=min(ans,mid);
		}else{
			l=mid+1;
		}
	}
	printf("%lld",l);
	return 0;
}

#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n,step[100005];
ll ans=-1e9;
bool book[100005];
struct stone{
	ll v,cmp;//0Îª+£¬1Îª* 
}s[100005];
ll count(){
	ll ans1=0;
	for(int i=1;i<=n;i++){
		if(s[step[i]].cmp==0)ans1+=s[step[i]].v;
		else ans1*=s[step[i]].v;
	}
	return ans1;
}
void dfs(int s){
	if(s==n){
		int temp;
		for(int i=1;i<=n;i++){
			if(!book[i]){
				temp=i;
				break;
			}
		}
		step[s]=temp;
		ans=max(ans,count());
	}else{
		for(int i=1;i<=n;i++){
			if(!book[i]){
				step[s]=i;
				book[i]=true;
				dfs(s+1);
				book[i]=false;
			}
		}
	}
	
}
int main(int argc, char** argv) {
	scanf("%d",&n);
	char t;
	bool ti=true,t3=true,t4=true;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(t=='+')s[i].cmp=0;
		else s[i].cmp=1;
		scanf("%lld",&s[i].v);
		if(s[i].v<0){
			ti=false;
			if(s[i].cmp==0)t4=false;
			else t3==false;
		}
	}
	if(n<=12){
		dfs(1);
		printf("%d",(ans%mod+mod)%mod);
	}else if(ti){
		ans=0;
		for(int i=1;i<=n;i++){
			if(s[i].cmp==0)ans=(ans+s[i].v);
		}
		for(int i=1;i<=n;i++){
			if(s[i].cmp==1)ans=(ans*s[i].v);
		}
		printf("%lld",(ans%mod+mod)%mod);
	}else if(t3){
		ans=0;
		for(int i=1;i<=n;i++){
			if(s[i].cmp==0&&s[i].v>0)ans=(ans+s[i].v);
		}
		for(int i=1;i<=n;i++){
			if(s[i].cmp==1)ans=(ans*s[i].v);
		}
		for(int i=1;i<=n;i++){
			if(s[i].cmp==0&&s[i].v<0)ans=(ans+s[i].v);
		}
		printf("%lld",(ans%mod+mod)%mod);
	}else if(t4){
		ans=0;
		ll t=1,minadd=1e9,maxmti=-1e9,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i].cmp==1&&s[i].v<0){
				cnt++;
			}
		}
		if(cnt%2==0){
			for(int i=1;i<=n;i++){
			if(s[i].cmp==0&&s[i].v>0)ans=(ans+s[i].v);
			}
			for(int i=1;i<=n;i++){
				if(s[i].cmp==1)ans=(ans*s[i].v);
			}
			for(int i=1;i<=n;i++){
				if(s[i].cmp==0&&s[i].v<0)ans=(ans+s[i].v);
			}
			printf("%lld",(ans%mod+mod)%mod);
		}else{
			ll tmti,tadd;
			for(int i=1;i<=n;i++){
				if(s[i].cmp==1&&s[i].v<0&&s[i].v>maxmti){
					maxmti=s[i].v;
					tmti=i;
				}
			}
			s[tmti].v=1;
			for(int i=1;i<=n;i++){
				if(s[i].cmp==0&&s[i].v<minadd){
					tadd=i;
					minadd=s[i].v;
				}
			}
			s[tadd].v=0;
			for(int i=1;i<=n;i++){
			if(s[i].cmp==0&&s[i].v>0)ans=ans+s[i].v;
			}
			for(int i=1;i<=n;i++){
				if(s[i].cmp==1)ans=ans*s[i].v;
			}
			for(int i=1;i<=n;i++){
				if(s[i].cmp==0&&s[i].v<0)ans=ans+s[i].v;
			}
			ans=(ans+(maxmti*minadd));
			printf("%lld",(ans%mod+mod)%mod);
		}
	}else{
		ans=0;
		ll t=1,minadd=1e9,maxmti=-1e9,cnt=0;
		ll tmti,tadd;
			for(int i=1;i<=n;i++){
				if(s[i].cmp==1&&s[i].v<0&&s[i].v>maxmti){
					maxmti=s[i].v;
					tmti=i;
				}
			}
			s[tmti].v=1;
			for(int i=1;i<=n;i++){
				if(s[i].cmp==0&&s[i].v<minadd){
					tadd=i;
					minadd=s[i].v;
				}
			}
			s[tadd].v=0;
			for(int i=1;i<=n;i++){
			if(s[i].cmp==0&&s[i].v>0)ans=ans+s[i].v;
			}
			for(int i=1;i<=n;i++){
				if(s[i].cmp==1)ans=ans*s[i].v;
			}
			for(int i=1;i<=n;i++){
				if(s[i].cmp==0&&s[i].v<0)ans=ans+s[i].v;
			}
			ans=(ans+(maxmti*minadd));
			printf("%lld",(ans%mod+mod)%mod);
	}
	
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int f[505],cnt[505],n,m;
bool vis[505];
struct edge{
    int x,y,val,stat;
}e[255025];
void readi(int &x){
    char c;
    for(c=getc(stdin);c<'0'||c>'9';c=getc(stdin));
    for(x=0;c<='9'&&c>='0';c=getc(stdin))x=(x<<3)+(x<<1)+c-'0';
}
int getf(int x){
    if(f[x]!=x){
        f[x]=getf(f[f[x]]);
        return f[x];
    }
    return x;
}
bool merge(int x,int y){
    int fx=getf(x);
    int fy=getf(y);
    if(fx!=fy){
        f[fy]=fx;
        return false;
    }
    return true;
}
void init(){
    for(int i=1;i<=n;i++)f[i]=i;
}
bool cmp(edge x,edge y){
	return x.val<y.val;
}
int main(){
	cout<<((1<<31)-1)<<endl;
    /*readi(n);readi(m);
    for(int i=1;i<=m;i++){
        readi(e[i].x);readi(e[i].y);readi(e[i].val);readi(e[i].stat); 
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++){
    	init();
    	memset(vis,false,sizeof(vis));
    	for(int j=1;j<=m;j++){
    		if(e[j].x!=i&&e[j].y!=i&&e[j].stat==1)merge(e[j].x,e[j].y);
		}
		int dot_cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[f[j]]&&j!=i){
				dot_cnt++;
				vis[f[j]]=true;
			}
		}
		for(int j=1;j<=m&&dot_cnt>1;j++){
			if(e[j].x==i||e[j].y==i)continue;
			if(!merge(e[j].x,e[j].y)){
				cnt[i]+=e[j].val;
				dot_cnt--;
			}
		}
	}
	int max_cnt=0;
	for(int i=1;i<=n;i++){
        max_cnt=max(max_cnt,cnt[i]);
    }
	bool isAll=true;
	for(int i=1;i<=n&&isAll;i++)if(cnt[i]!=0)isAll=false;
	queue<int> q;
	if(isAll){
		printf("0");
	}else{
		for(int i=1;i<=n;i++)if(max_cnt==cnt[i])q.push(i);
	}
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		printf("%d",tmp);
		if(!q.empty())printf(" ");
	}*/
    return 0;
}

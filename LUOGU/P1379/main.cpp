#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#define ll long long
using namespace std;
ll t,ans=123804765;
int temp[5][5];
int movet[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int lake{5}; 
int main(int argc, char** argv) {
	scanf("%lld",&t);
	if(t==ans){
		puts("0");
		return 0;
		
	}
	map<ll,ll> check,f;
	check[t]=0;
	check[ans]=1;
	queue<ll> bfs;
	bfs.push(t);
	bfs.push(ans);
	f[ans]=1;
	f[t]=2;
	while(!bfs.empty()){
		
		t=bfs.front();bfs.pop();
		int tt=t;
		int tx=0,ty=0;
		for(int i=3;i>=1;i--){
			for(int j=3;j>=1;j--){
				temp[i][j]=tt%10;tt/=10;
				if(temp[i][j]==0){
					tx=i;ty=j;
				}
			}
		}
		int x,y,val=0;
		for(int i=0;i<4;i++){
			val=0;
			x=tx+movet[i][0];
			y=ty+movet[i][1];
			if(x>3||y>3||x<=0||y<=0)continue;
			swap(temp[tx][ty],temp[x][y]);
			for(int k=1;k<=3;k++){
				for(int j=1;j<=3;j++){
					val=val*10+temp[k][j];
				}
			}
			if(f[val]==f[t]){
				swap(temp[tx][ty],temp[x][y]);
				continue;
			}
			if(f[val]+f[t]==3){
				printf("%lld",check[val]+check[t]);
				return 0;
			}
			f[val]=f[t];
			check[val]=check[t]+1;
			bfs.push(val);
			swap(temp[tx][ty],temp[x][y]);
			
		}
	}
	return 0;
}

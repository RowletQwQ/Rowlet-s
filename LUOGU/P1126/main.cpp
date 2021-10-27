#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
struct robot{
	int x,y,head,time;
}bfs[250005],Rend; 
bool book[55][55],mem[55][55][4];
int step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,l,r=1;
bool cmp(robot x,robot y){
	if(x.x==y.x&&x.y==y.y)return true;
	return false;
}
int main(int argc, char** argv) {
	scanf("%d%d",&n,&m);
	int t,tx,ty;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&t);
			book[i][j]=t;
		}
	}
	scanf("%d%d%d%d",&bfs[0].x,&bfs[0].y,&Rend.x,&Rend.y);
	char heading;
	cin>>heading;
	switch(heading){
		case 'E':bfs[0].head=0;break;
		case 'S':bfs[0].head=1;break;
		case 'W':bfs[0].head=2;break;
		case 'N':bfs[0].head=3;break;
	}
	mem[bfs[0].x][bfs[0].y][bfs[0].head]=true;
	bfs[0].time=0;
	while(l<r){
		//cout<<bfs[l].x<<" "<<bfs[l].y<<" "<<bfs[l].head<<endl; 
		if(cmp(bfs[l],Rend)){
			printf("%d",bfs[l].time);
			return 0;
		}
		t=((bfs[l].head)+1)%4;
		if(!mem[bfs[l].x][bfs[l].y][t]){
			bfs[r]=bfs[l];bfs[r].head=t;
			bfs[r].time++;
			mem[bfs[l].x][bfs[l].y][t]=true;
			r++;
		}
		t=(bfs[l].head)-1;
		if(t<0)t=3;
		if(!mem[bfs[l].x][bfs[l].y][t]){
			bfs[r]=bfs[l];bfs[r].head=t;
			bfs[r].time++;
			mem[bfs[l].x][bfs[l].y][t]=true;
			r++;
		}
		
		
		for(int j=1;j<=3;j++){
			int thead=bfs[l].head;
			tx=bfs[l].x+(step[thead][0]*j);
			ty=bfs[l].y+(step[thead][1]*j);
			if(book[tx][ty]||tx>n-1||ty>m-1||tx<=0||ty<=0||book[tx+1][ty]||book[tx][ty+1]||book[tx+1][ty+1])break;
			if(mem[tx][ty][bfs[l].head])continue;
			bfs[r].x=tx;bfs[r].y=ty;bfs[r].head=bfs[l].head;bfs[r].time=bfs[l].time+1;
			mem[tx][ty][bfs[r].head]=true;
			r++;
		}
		
		l++;
		
	}	
	printf("-1");
	
	
	return 0;
}
